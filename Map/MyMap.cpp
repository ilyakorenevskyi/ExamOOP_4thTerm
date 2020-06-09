#ifndef MYMAP_CPP
#define MYMAP_CPP
#include "MyMap.h"
template<typename K, typename T>
MyMapTree<K, T>::MyMapTree() {
	tree = new SplayTree<K, T>();
}

template<typename K, typename T>
T MyMapTree<K, T>::get(K key) {
	return tree->search(key)->getValue();
}

template<typename K, typename T>
void MyMapTree<K, T>::set(K key, T value) {
	TreeNode<K, T>* cur = tree->search(key);
	if (cur->getKey() == key)  cur->setValue(value);
	else  add(key, value);
}

template<typename K, typename T>
void MyMapTree<K, T>::add(K key, T value) {
	tree->insert(value, key);
}

template<typename K, typename T>
void MyMapTree<K, T>::remove(K key) {
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
std::vector<std::pair<K, T>> MyMapTree<K, T>::getPairs() {
	return tree->preOrder();
}


template<typename K, typename T>
MapAdapterToMyMap<K, T>::MapAdapterToMyMap() {
}

template<typename K, typename T>
inline T MapAdapterToMyMap<K, T>::get(K key)
{
	return map_[key];
}

template<typename K, typename T>
void MapAdapterToMyMap<K, T>::set(K key, T value) {
	if (map_.find(key) != map_.end()) add(key, value);
	else map_[key] = value;
}

template<typename K, typename T>
void MapAdapterToMyMap<K, T>::add(K key, T value) {
	map_[key] = value;
}

template<typename K, typename T>
void MapAdapterToMyMap<K, T>::remove(K key) {
	map_.erase(key);
}

template<typename K, typename T>
std::vector<K> MapAdapterToMyMap<K, T>::getKeys() {
	std::vector<K> res;
	for (auto iter : map_) {
		res.push_back(iter.first);
	}
	return res;

}

template<typename K, typename T>
inline std::vector<T> MapAdapterToMyMap<K, T>::getValues()
{
	std::vector<T> res;
	for (auto iter : map_)
		res.push_back(iter.second);
	return res;
}

template<typename K, typename T>
inline std::vector<std::pair<K, T>> MapAdapterToMyMap<K, T>::getPairs()
{
	std::vector<std::pair<K, T>> res;
	for (auto iter : map_)
		res.push_back({ iter.first,iter.second });
	return res;
}

#endif