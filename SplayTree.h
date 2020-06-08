#pragma once
#include <iostream>
template <typename K, typename T>
class SplayTree;
template <typename K, typename T>
class TreeNode{
	K key;
	T obj;
	TreeNode<K,T>* left, * right;
public:
	friend class SplayTree<K,T>;
	TreeNode(T obj, K key);
	T getValue();
	void setValue(T);
	K getKey();
};
template <typename K, typename T>
class SplayTree {
	TreeNode<K, T>* root;
	void preOrderRec(TreeNode<K, T>*);
	TreeNode<K, T>* rightRotate(TreeNode<K,T>* x);
	TreeNode<K,T>* leftRotate(TreeNode<K,T>* x);
	TreeNode<K,T>* splay(TreeNode<K,T>* root_,K key);
public:
	TreeNode<K, T>* search(K key);
	void insert(T obj,K key);
	void preOrder();
	TreeNode<K,T>* delete_key(K key);
};

