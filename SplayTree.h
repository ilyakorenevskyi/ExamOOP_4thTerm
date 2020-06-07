#pragma once
#include <iostream>
class SplayTree
{
};
template <typename T>
class TreeNode{
public:
	int key;
	T obj;
	TreeNode<T>* left, * right;
};
template <typename T>
TreeNode<T>* newNode(T obj)
{
	TreeNode<T>* Node = new TreeNode<T>();
	Node->key = obj->key;
	Node->obj = obj;
	Node->left = Node->right = nullptr;
	return (Node);
}
template <typename T>
TreeNode<T>* rightRotate(TreeNode<T>* x) // rotate right
{
	TreeNode<T>* y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}
template <typename T>
TreeNode<T>* leftRotate(TreeNode<T>* x) // rotate left
{
	TreeNode<T>* y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}
template <typename T>
TreeNode<T>* splay(TreeNode<T>* root, int key) //splay function
{
	if (root == nullptr || root->key == key)
		return root;

	if (root->key > key)  //root in left child
	{
		if (root->left == nullptr) return root; //if left child if empty


		if (root->left->key > key) // Left-Left case (Zig-zig) 
		{
			root->left->left = splay(root->left->left, key); //change root (recursion)
			root = rightRotate(root);  //first right rotation
		}
		else if (root->left->key < key) // Zig-Zag (Left Right)  
		{
			root->left->right = splay(root->left->right, key); //change root
			if (root->left->right != nullptr)
				root->left = leftRotate(root->left); // first left rotation
		}

		return (root->left == nullptr) ? root : rightRotate(root); // do second rotation if we need it
	}
	else //root in left child
	{
		if (root->right == nullptr) return root;

		if (root->right->key < key)// Right-Right case (zag-zag)  
		{
			root->right->right = splay(root->right->right, key);
			root = leftRotate(root);
		}
		else if (root->right->key > key)// Right-Left case (Zag-zig) 
		{
			root->right->left = splay(root->right->left, key);
			if (root->right->left != nullptr)
				root->right = rightRotate(root->right);
		}

		return (root->right == nullptr) ? root : leftRotate(root); // Do second rotation for root  if we need
	}
}
template <typename T>
TreeNode<T>* search(TreeNode<T>* root, int key)
{
	return splay(root, key);
}
template <typename T>
void preOrder(TreeNode<T>* root)  //returns tree
{
	if (root != nullptr)
	{
		std::cout << root->obj->name << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
template <typename T>
TreeNode<T>* insert(TreeNode<T>* root, T* obj)
{
	// if tree is empty 

	if (root == nullptr) return newNode(obj);

	// make closest key to our key root  
	root = splay(root, obj->key);

	// if key is already in tree
	if (root->key == obj->key) return root;

	TreeNode<T>* newTreeNode<T> = newNode(obj); //allocate memory for new element

	if (root->key > obj->key) //if root bigger than key then make it new right child, and root's left  child make new left child
	{
		newTreeNode<T>->right = root;
		newTreeNode<T>->left = root->left;
		root->left = nullptr;
	}


	else //if root smaller  than key then make it new left child, and root's right  child make new right child
	{
		newTreeNode<T>->left = root;
		newTreeNode<T>->right = root->right;
		root->right = nullptr;
	}

	return newTreeNode<T>; // newTreeNode<T> becomes new root  
}
template <typename T>
TreeNode<T>* delete_key(TreeNode<T>* root, int key)
{
	TreeNode<T>* temp;
	if (!root)
		return nullptr;

	root = splay(root, key); //splay given tree

	if (key != root->key) //if there is no key to delete, then return same tree
		return root;

	if (!root->left)  //if left child doesn't exist, make right child new root
	{
		temp = root;
		root = root->right;
	}

	// Else if left child exits 
	else
	{
		temp = root;

		root = splay(root->left, key); //root will have max key from left child, since key is bigger than left child
		root->right = temp->right;  //right child become new right child
	}
	return root;
}

