#pragma once
#include "Sortings/Sortings.h"
#include "LinkedList.h"
template<typename T>
class MySortingList{
	SortingStrategy<T>* sort;
	LinkedList<T> array;
public:
	MySortingList();
	void setSorting(SortingStrategy<T>*);
	void setComparation(bool(*comp_)(T , T));
	void sortArray();
	void add(T);
	void getElemBeg(size_t amount);
	void getElemEnd(size_t amount);
	void getElemMid(size_t amount);
	void getElemPod(size_t amount, size_t pos);
};

template<typename T>
 MySortingList<T>::MySortingList(){
	
}

template<typename T>
void MySortingList<T>::setSorting(SortingStrategy<T>* new_sort){
	this->sort = new_sort;
}

template<typename T>
void MySortingList<T>::setComparation(bool(*comp_)(T, T)){
	sort->setComp(comp_);
}

template<typename T>
void MySortingList<T>::sortArray(){
	std::vector<T> temp = array.toVector();
	sort->sort(temp, 0, temp.size() - 1);
	array = LinkedList<T>(temp);

}

template<typename T>
void MySortingList<T>::add(T obj){
	array.add(obj);
}


