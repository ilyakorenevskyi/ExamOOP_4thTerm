#pragma once
#include <vector>

template <typename K,typename T>
class SeparateHash{
	std::vector<std::vector<std::pair<K, T>>> hashtable;
	size_t hash_size;
	void add(K key, T value);
	void set(K key, T value);
	T getValue(K key);
};

