#include <iostream>
#include "Tree/SplayTree.h"
#include "Tree/BPlusTree.h"
#include "Sortings/Sortings.h"
#include "Map/MyMap.h"
int main() {
	MapAdapterToMyMap<int, int> m1;
	m1.add(12, 3);
	m1.add(13, 4);
	cout << m1.get(13);
	return 0;
}