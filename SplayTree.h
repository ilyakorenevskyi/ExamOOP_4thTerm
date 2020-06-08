#pragma once
#include <iostream>
template <typename T>
class SplayTree;
template <typename T>
class TreeNode{
	int key;
	T obj;
	TreeNode<T>* left, * right;
public:
	friend class SplayTree<T>;
	TreeNode(T obj, int key);
};
template <typename T>
class SplayTree {
	TreeNode<T>* root;

	TreeNode<T>* rightRotate(TreeNode<T>* x);
	TreeNode<T>* leftRotate(TreeNode<T>* x);
	TreeNode<T>* splay(TreeNode<T>* root_,int key);
	TreeNode<T>* search(int key);
	TreeNode<T>* insert(T obj,int key);
	void preOrderRec(TreeNode<T>*);
	void preOrder();
	TreeNode<T>* delete_key(int key);
};

