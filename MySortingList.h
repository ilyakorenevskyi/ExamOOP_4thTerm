#pragma once
#include "Sortings/Sortings.h"
#include "LinkedList.h"
template<typename T>
class MySortingList{
	SortingStrategy<T>* sort;
	LinkedList<T> array;
public:
	void setSorting(SortingStrategy<T>*);
	void setComparation(bool(*comp_)(T , T));
	void sortArray();
	void add(T);
	void getElemBeg(size_t amount);
	void getElemEnd(size_t amount);
	void getElemMid(size_t amount);
	void getElemPod(size_t amount, size_t pos);
};

