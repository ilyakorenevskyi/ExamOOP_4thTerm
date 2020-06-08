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
};
template <typename K, typename T>
class SplayTree {
	TreeNode<K, T>* root;

	TreeNode<K, T>* rightRotate(TreeNode<K,T>* x);
	TreeNode<K,T>* leftRotate(TreeNode<K,T>* x);
	TreeNode<K,T>* splay(TreeNode<K,T>* root_,K key);
	TreeNode<K,T>* search(K key);
	TreeNode<K,T>* insert(T obj,K key);
	void preOrderRec(TreeNode<K,T>*);
	void preOrder();
	TreeNode<K,T>* delete_key(K key);
};

