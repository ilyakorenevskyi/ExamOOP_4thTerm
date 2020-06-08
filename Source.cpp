#include <iostream>
#include "SplayTree.h"
#include "BPlusTree.h"
#include "Sortings.h"
#include "MyMap.h"
int main() {
	MyMapTree<int, int> m1;
	m1.add(1, 2);
	m1.add(2, 3);
	std::cout << m1.get(1);
	return 0;
}