#include "SplayTree.h"
template <typename T>
TreeNode<T>::TreeNode(T obj, int key){
	this->key = key;
	this->obj = obj;
	this->left = this->right = nullptr;
}
template <typename T>
TreeNode<T>* SplayTree<T>::rightRotate(TreeNode<T>* x) // rotate right
{
	TreeNode<T>* y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}
template <typename T>
TreeNode<T>* SplayTree<T>::leftRotate(TreeNode<T>* x) // rotate left
{
	TreeNode<T>* y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}
template <typename T>
TreeNode<T>* SplayTree<T>::splay(TreeNode<T>* root_,int key) //splay function
{
	if (root_ == nullptr || root_->key == key)
		return root_;

	if (root_->key > key)  //root_ in left child
	{
		if (root_->left == nullptr) return root_; //if left child if empty


		if (root_->left->key > key) // Left-Left case (Zig-zig) 
		{
			root_->left->left = splay(root_->left->left, key); //change root_ (recursion)
			root_ = rightRotate(root_);  //first right rotation
		}
		else if (root_->left->key < key) // Zig-Zag (Left Right)  
		{
			root_->left->right = splay(root_->left->right, key); //change root_
			if (root_->left->right != nullptr)
				root_->left = leftRotate(root_->left); // first left rotation
		}

		return (root_->left == nullptr) ? root_ : rightRotate(root_); // do second rotation if we need it
	}
	else //root_ in left child
	{
		if (root_->right == nullptr) return root_;

		if (root_->right->key < key)// Right-Right case (zag-zag)  
		{
			root_->right->right = splay(root_->right->right, key);
			root_ = leftRotate(root_);
		}
		else if (root_->right->key > key)// Right-Left case (Zag-zig) 
		{
			root_->right->left = splay(root_->right->left, key);
			if (root_->right->left != nullptr)
				root_->right = rightRotate(root_->right);
		}

		return (root_->right == nullptr) ? root_ : leftRotate(root_); // Do second rotation for root_  if we need
	}
}
template <typename T>
TreeNode<T>* SplayTree<T>::search( int key)
{
	this->root = splay(this->root, key);
}
template <typename T>
void SplayTree<T>::preOrderRec(TreeNode<T>* root_) {
	if (root_ != nullptr)
	{
		std::cout << root_->obj << " ";
		preOrderRec(root_->left);
		preOrderRec(root_->right);
	}
}
template <typename T>
void SplayTree<T>::preOrder()  //returns tree
{
	preOrderRec(this->root);
}
template <typename T>
TreeNode<T>* SplayTree<T>::insert(T obj,int key)
{
	// if tree is empty 


	if (root == nullptr) return  TreeNode<T>*(obj,key);

	// make closest key to our key root  
	root = splay(root, obj->key);

	// if key is already in tree
	if (root->key == obj->key) return root;

	TreeNode<T>* newTreeNode = new TreeNode<T> * (obj, key); //allocate memory for new element

	if (root->key > obj->key) //if root bigger than key then make it new right child, and root's left  child make new left child
	{
		newTreeNode->right = root;
		newTreeNode->left = root->left;
		root->left = nullptr;
	}


	else //if root smaller  than key then make it new left child, and root's right  child make new right child
	{
		newTreeNode->left = root;
		newTreeNode->right = root->right;
		root->right = nullptr;
	}

	return newTreeNode; // newTreeNode<T> becomes new root  
}
template <typename T>
TreeNode<T>* SplayTree<T>::delete_key(int key){
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
