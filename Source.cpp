#include <iostream>
#include "SplayTree.h"
#include "BPlusTree.h"
#include "Sortings.h"
int main() {
	InsertionSort<int> merg;
	vector<int> v = { 1,5,3,2,7 };
	merg.sort(v, 0, 4);
	return 0;
}