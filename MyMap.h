#pragma once
#include <vector>
#include "SplayTree.h"
#include "SeparateHash.h"
template <typename K, typename T>
class MyMap{
	virtual T get(K key) = 0;
	virtual void set(K key, T value) = 0;
	virtual void add(K key, T value) = 0;
	virtual void remove(K key) = 0;
	virtual std::vector<K> getKeys() = 0;
	virtual std::vector<T> getValues() = 0;
	virtual std::vector<std::pair<K,T>> getPairs() = 0;
};
//template <typename T, typename K>
//class MyMapHash:public MyMap<K,T> {
//	Hash table;
//
//};
template <typename K, typename T>
class MyMapTree :public MyMap<K, T> {
	SplayTree<K, T>* tree;
public:
	MyMapTree();
	T get(K key) override;
	void set(K key, T value) override;
	void add(K key, T value) override;
	void remove(K key) override;
	std::vector<K> getKeys() override;
	std::vector<T> getValues() override;
	std::vector<std::pair<K, T>> getPairs() override;
};

template<typename K, typename T>
 MyMapTree<K, T>::MyMapTree(){
	 tree = new SplayTree<K,T>();
}

template<typename K, typename T>
T MyMapTree<K, T>::get(K key){
	return tree->search(key)->getValue();
}

template<typename K, typename T>
 void MyMapTree<K, T>::set(K key, T value){
	TreeNode<K, T>* cur = tree->search(key);
	if (cur->getKey() == key)  cur->setValue(value);
	else  add(key, value);
}

template<typename K, typename T>
void MyMapTree<K, T>::add(K key, T value){
	tree->insert(value, key);
}

template<typename K, typename T>
void MyMapTree<K, T>::remove(K key){
	tree->delete_key(key);
}

template<typename K, typename T>
inline std::vector<K> MyMapTree<K, T>::getKeys()
{
	std::vector<K> result;
	std::vector<std::pair<K, T>> pairs = tree->preOrder();
	for (auto cur : pairs) {
		result.push_back(cur.first);
	}
	return result;
}

template<typename K, typename T>
 std::vector<T> MyMapTree<K, T>::getValues()
{
	std::vector<T> result;
	std::vector<std::pair<K, T>> pairs = tree->preOrder();
	for (auto cur : pairs) {
		result.push_back(cur.second);
	}
	return result;
}

 template<typename K, typename T>
std::vector<std::pair<K, T>> MyMapTree<K, T>::getPairs()
 {
	 return tree->preOrder();

 }


template <typename K, typename T>
class MyMapHash :public MyMap<K, T> {
	SeparateHash<K, T>* hash;
public:
	MyMapHash();
	T get(K key) override;
	void set(K key, T value) override;
	void add(K key, T value) override;
	void remove(K key) override;
	std::vector<K> getKeys() override;
	std::vector<T> getValues() override;
	std::vector<std::pair<K, T>> getPairs() override;
};