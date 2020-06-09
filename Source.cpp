#include <iostream>
#include "SplayTree.h"
#include "BPlusTree.h"
#include "Sortings.h"
#include "MyMap.h"
int main() {
	MapAdapterToMyMap<int, int> m1;
	m1.add(12, 3);
	m1.add(13, 4);
	cout << m1.get(13);
	return 0;
}