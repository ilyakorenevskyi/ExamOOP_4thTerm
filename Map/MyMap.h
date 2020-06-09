#ifndef MYMAP_H
#define MYMAP_H

#include <vector>
#include <map>
#include "../Tree/SplayTree.h"
#include "../Hash/SeparateHash.h"

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
class MyMapTree :public MyMap<K, T> {		//Adapter Pattern
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
class MapAdapterToMyMap : public MyMap<K, T> {     //Adapter Pattern
	std::map<K, T> map_;
public:
	MapAdapterToMyMap();
	T get(K key) override;
	void set(K key, T value) override;
	void add(K key, T value) override;
	void remove(K key) override;
	std::vector<K> getKeys() override;
	std::vector<T> getValues() override;
	std::vector<std::pair<K, T>> getPairs() override;
};

template <typename K, typename T>
class MyMapHash :public MyMap<K, T> {          //Adapter Pattern
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

#include"MyMap.cpp"

#endif