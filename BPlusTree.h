// Searching on a B+ tree in C++


#include <iostream>

using namespace std;
int const MAX = 3;

// BP node
class Node {
    bool IS_LEAF;
    int* key, size;
    Node** ptr;
    friend class BPTree;

public:
    Node();
};

// BP tree
class BPTree {
    Node* root;
    void insertInternal(int, Node*, Node*);
    Node* findParent(Node*, Node*);

public:
    BPTree();
    void search(int);
    void insert(int);
    void display(Node*);
    Node* getRoot();
};
