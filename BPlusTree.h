#ifndef BPLUSTREE_H
#define BPLUSTREE_H


#include <iostream>

using namespace std;
int const MAX = 3;
template <typename K, typename T>
class BPTree;

// BP node
template <typename K,typename T>
class Node {
    bool is_leaf;
    std::pair<K, T>* obj;
    int size;
    Node<K,T>** ptr;
    friend class BPTree<K,T>;

public:
    Node();
};


template <typename K, typename T>
class BPTree {
    Node<K,T>* root;
    void insertInternal(std::pair<K, T> x, Node<K, T>* cursor, Node<K, T>* child);
    Node<K,T>* findParent(Node<K,T>*, Node<K,T>*);

public:
    BPTree();
    void search(K);
    void insert(K,T);
    //void display(Node*);
    Node<K,T>* getRoot();
};
 
#include "BPlusTree.cpp"
#endif