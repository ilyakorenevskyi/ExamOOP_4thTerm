#ifndef BPLUSTREE_CPP
#define BPLUSTREE_CPP

#include "BPlusTree.h"

template <typename K, typename T>
Node<K,T>::Node() {
    obj = new std::pair<K, T>[MAX];
    ptr = new Node * [MAX + 1];
}

template <typename K, typename T>
BPTree<K,T>::BPTree() {
    root = nullptr;
}

// Search operation
template <typename K, typename T>
void BPTree<K,T>::search(K x) {
    if (root == nullptr) {
        cout << "Tree is empty\n";
    }
    else {
        Node<K,T>* cursor = root;
        while (cursor->is_leaf == false) {
            for (int i = 0; i < cursor->size; i++) {
                if (x < cursor->obj[i].first) {
                    cursor = cursor->ptr[i];
                    break;
                }
                if (i == cursor->size - 1) {
                    cursor = cursor->ptr[i + 1];
                    break;
                }
            }
        }
        for (int i = 0; i < cursor->size; i++) {
            if (cursor->obj[i].first == x) {
                cout << "Found\n";
                return;
            }
        }
        cout << "Not found\n";
    }
}

// Insert Operation
template <typename K, typename T>
void BPTree<K,T>::insert(K x,T value) {
    if (root == nullptr) {
        root = new Node<K,T>;
        root->obj[0] = { x,value };
        root->is_leaf = true;
        root->size = 1;
    }
    else {
        Node<K,T>* cursor = root;
        Node<K,T>* parent = nullptr;
        while (cursor->is_leaf == false) {
            parent = cursor;
            for (int i = 0; i < cursor->size; i++) {
                if (x < cursor->obj[i].first) {
                    cursor = cursor->ptr[i];
                    break;
                }
                if (i == cursor->size - 1) {
                    cursor = cursor->ptr[i + 1];
                    break;
                }
            }
        }
        if (cursor->size < MAX) {
            int i = 0;
            while (x > cursor->obj[i].first && i < cursor->size)
                i++;
            for (int j = cursor->size; j > i; j--) {
                cursor->obj[j] = cursor->obj[j-1];
            }
            cursor->obj[i] = { x,value};
            cursor->size++;
            cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
            cursor->ptr[cursor->size - 1] = nullptr;
        }
        else {
            Node<K,T>* newLeaf = new Node<K,T>;
            std::pair<K,T> virtualNode[MAX + 1];
            for (int i = 0; i < MAX; i++) {
                virtualNode[i] = cursor->obj[i];
            }
            int i = 0, j;
            while (x > virtualNode[i].first && i < MAX)
                i++;
            for (int j = MAX + 1; j > i; j--) {
                virtualNode[j] = virtualNode[j - 1];
            }
            virtualNode[i] = { x,value };
            newLeaf->is_leaf = true;
            cursor->size = (MAX + 1) / 2;
            newLeaf->size = MAX + 1 - (MAX + 1) / 2;
            cursor->ptr[cursor->size] = newLeaf;
            newLeaf->ptr[newLeaf->size] = cursor->ptr[MAX];
            cursor->ptr[MAX] = nullptr;
            for (i = 0; i < cursor->size; i++) {
                cursor->obj[i] = virtualNode[i];
            }
            for (i = 0, j = cursor->size; i < newLeaf->size; i++, j++) {
                newLeaf->obj[i] = virtualNode[j];
            }
            if (cursor == root) {
                Node<K,T>* newRoot = new Node<K,T>;
                newRoot->obj[0] = newLeaf->obj[0];
                newRoot->ptr[0] = cursor;
                newRoot->ptr[1] = newLeaf;
                newRoot->is_leaf = false;
                newRoot->size = 1;
                root = newRoot;
            }
            else {
                insertInternal(newLeaf->obj[0], parent, newLeaf);
            }
        }
    }
}

// Insert Operation
template <typename K, typename T>
void BPTree<K,T>::insertInternal(std::pair<K,T> x, Node<K,T>* cursor, Node<K,T>* child) {
    if (cursor->size < MAX) {
        int i = 0;
        while (x.first > cursor->obj[i].first && i < cursor->size)
            i++;
        for (int j = cursor->size; j > i; j--) {
            cursor->obj[j] = cursor->obj[j - 1];
        }
        for (int j = cursor->size + 1; j > i + 1; j--) {
            cursor->ptr[j] = cursor->ptr[j - 1];
        }
        cursor->obj[i] = x;
        cursor->size++;
        cursor->ptr[i + 1] = child;
    }
    else {
        Node<K,T>* newInternal = new Node<K,T>;
        std::pair<K, T>  virtualKey[MAX + 1];
        Node<K,T>* virtualPtr[MAX + 2];
        for (int i = 0; i < MAX; i++) {
            virtualKey[i] = cursor->obj[i];
        }
        for (int i = 0; i < MAX + 1; i++) {
            virtualPtr[i] = cursor->ptr[i];
        }
        int i = 0, j;
        while (x.first > virtualKey[i].first && i < MAX)
            i++;
        for (int j = MAX + 1; j > i; j--) {
            virtualKey[j] = virtualKey[j - 1];
        }
        virtualKey[i] = x;
        for (int j = MAX + 2; j > i + 1; j--) {
            virtualPtr[j] = virtualPtr[j - 1];
        }
        virtualPtr[i + 1] = child;
        newInternal->is_leaf = false;
        cursor->size = (MAX + 1) / 2;
        newInternal->size = MAX - (MAX + 1) / 2;
        for (i = 0, j = cursor->size + 1; i < newInternal->size; i++, j++) {
            newInternal->obj[i] = virtualKey[j];
        }
        for (i = 0, j = cursor->size + 1; i < newInternal->size + 1; i++, j++) {
            newInternal->ptr[i] = virtualPtr[j];
        }
        if (cursor == root) {
            Node* newRoot = new Node;
            newRoot->obj[0] = cursor->obj[cursor->size];
            newRoot->ptr[0] = cursor;
            newRoot->ptr[1] = newInternal;
            newRoot->is_leaf = false;
            newRoot->size = 1;
            root = newRoot;
        }
        else {
            insertInternal(cursor->key[cursor->size], findParent(root, cursor), newInternal);
        }
    }
}

// Find the parent
template <typename K,typename T>
Node<K,T>* BPTree<K,T>::findParent(Node<K,T>* cursor, Node<K,T>* child) {
    Node<K,T>* parent = nullptr;
    if (cursor->is_leaf || (cursor->ptr[0])->is_leaf) {
        return nullptr;
    }
    for (int i = 0; i < cursor->size + 1; i++) {
        if (cursor->ptr[i] == child) {
            parent = cursor;
            return parent;
        }
        else {
            parent = findParent(cursor->ptr[i], child);
            if (parent != nullptr)
                return parent;
        }
    }
    return parent;
}

//// Print the tree
//void BPTree::display(Node* cursor) {
//    if (cursor != nullptr) {
//        for (int i = 0; i < cursor->size; i++) {
//            cout << cursor->key[i] << " ";
//        }
//        cout << "\n";
//        if (cursor->is_leaf != true) {
//            for (int i = 0; i < cursor->size + 1; i++) {
//                display(cursor->ptr[i]);
//            }
//        }
//    }
//}

// Get the root
template <typename K,typename T>
Node<K,T>* BPTree<K,T>::getRoot() {
    return root;
}

#endif