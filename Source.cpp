#include <iostream>
#include "Tree/SplayTree.h"
#include "Sortings/Sortings.h"
#include "MySortingList.h"
#include "Map/MyMap.h"
int main() {
	MySortingList<int> l;
	l.add(2);
	l.add(1);
	l.add(3);
	l.add(1);
	l.add(3);
	SortingStrategy<int>* merge = new MergeSort<int>();
	l.setSorting(merge);
	l.sortArray();
	return 0;
}