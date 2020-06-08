#pragma once
#include <vector>

template <typename K,typename T>
class SeparateHash{
	std::vector<std::vector<std::pair<K, T>>> hashtable;
	size_t hash_size;
	bool secondhash_enable;
	std::hash<K> hash1;
public:
	SeparateHash();
	SeparateHash(size_t new_size = 97, bool second_hash = false);
	void insert(K key, T value);
	void deleteKey(K key);
	T search(K key);
};

template<typename K, typename T>
SeparateHash<K, T>::SeparateHash(){
	hash_size = 97;
	hashtable.resize(hash_size);
	secondhash_enable = 0;
}

template<typename K, typename T>
SeparateHash<K, T>::SeparateHash(size_t new_size, bool second_hash){
	this->hash_size = new_size;
	this->hashtable.reserve(new_size);
	this->secondhash_enable = second_hash;
}

template<typename K, typename T>
void SeparateHash<K, T>::insert(K key, T value){
	hashtables[hash1(key) / hash_size].push_back({ key,value });
}

template<typename K, typename T>
void SeparateHash<K, T>::deleteKey(K key){
	std::vector<std::pair<K, T>> cur_chain = hashtables[hash1(key) / hash_size];
	for (int i = 0; i < cur_chain.size(); i++) {
		if (cur_chain[i].first == key) { 
			cur_chain.erase(cur_chain.begin() + i);
			break;
		}
	}
}

template<typename K, typename T>
T SeparateHash<K, T>::search(K key) {
	std::vector<std::pair<K, T>> cur_chain = hashtables[hash1(key) / hash_size];
	for (int i = 0; i < cur_chain.size(); i++) {
		if (cur_chain[i].first == key) {
			return cur_chain[i].second;
		}
	}
}