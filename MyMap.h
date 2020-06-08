#pragma once
#include <vector>
#include "SplayTree.h"
template <typename T, typename K>
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
template <typename T, typename K>
class MyMapTree :public MyMap<K, T> {
	SplayTree<K, T> tree;
	T get(K key) override;
	void set(K key, T value) override;
	void add(K key, T value) override;
	void remove(K key) override;
	std::vector<K> getKeys() override;
	std::vector<T> getValues() override;
	std::vector<std::pair<K, T>> getPairs() override;
};

template<typename T, typename K>
T MyMapTree<T, K>::get(K key){
	return tree.search(key)->getValue();
}

template<typename T, typename K>
 void MyMapTree<T, K>::set(K key, T value){
	TreeNode<K, T>* cur = tree.search(key);
	if (cur->getKey() == key)  cur->setValue(value);
	else  add(key, value);
}

template<typename T, typename K>
void MyMapTree<T, K>::add(K key, T value){
	tree.insert(value, key);
}

template<typename T, typename K>
void MyMapTree<T, K>::remove(K key){
	tree->delete_key(key);
}
