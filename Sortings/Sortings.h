#pragma once
#include <vector>
template <typename T>
class SortingStrategy{
protected:
	bool (*comp) (T first, T second);
public:
	SortingStrategy();
	SortingStrategy(bool (*comp_)(T, T));
	void setComp(bool (*comp_)(T, T));
	virtual void sort(std::vector<T>&, int, int)  = 0;
	virtual ~SortingStrategy() {}
};
template <typename T>
class InsertionSort: public SortingStrategy<T> {
public:
	InsertionSort() {}
	void sort(std::vector<T>&, int, int)  override;
	~InsertionSort() override {}
};
template <typename T>
class QuickSort : public SortingStrategy<T> {
public:
	QuickSort() {}
	void sort(std::vector<T>&, int, int)  override;
	~QuickSort() override {}
};
template <typename T>
class MergeSort : public SortingStrategy<T> {
public:
	MergeSort() {}
	
	void sort( std::vector<T>&, int, int)  override;
	void merge(std::vector<T>&, int, int);
	~MergeSort() override {}
};
template <typename T>
class CountSort : public SortingStrategy<T> {
public:
	CountSort() {}
	void sort(std::vector<T>&, int, int) override;
	~CountSort() override {}
};
template<typename T>
SortingStrategy<T>::SortingStrategy() {
    comp = [](T  first, T second) { return first < second; };
}

template<typename T>
SortingStrategy<T>::SortingStrategy(bool(*comp_)(T, T))
{
    comp = comp_;
}
template<typename T>
void QuickSort<T>::sort(std::vector<T>& to_sort, int beg, int end) {
    int i = beg;
    int j = end;
    T tmp;
    T pivot = to_sort[(beg + end) / 2];
    while (i <= j) {
        while ( SortingStrategy<T>::comp(to_sort[i], pivot)) {
            i++;
        }
        while (!SortingStrategy<T>::comp(to_sort[j], pivot)) {
            j--;
        }
        if (i <= j) {
            tmp = to_sort[i];
            to_sort[i] = to_sort[j];
            to_sort[j] = tmp;
            i++;
            j--;
        }
    }
    if (beg < j)
        sort(to_sort, beg, j);
    if (i < end)
        sort(to_sort, i, end);
}
template<typename T>
void InsertionSort<T>::sort(std::vector<T>& to_sort, int beg, int end) {
    int j;
    T key;
    for (int i = 1; i <= end; i++)
    {
        key = to_sort[i];
        j = i - 1;

        while (j >= 0 && ! SortingStrategy<T>::comp(to_sort[j], key))
        {
            to_sort[j + 1] = to_sort[j];
            j = j - 1;
        }
        to_sort[j + 1] = key;
    }
}
template<typename T>
void MergeSort<T>::sort(std::vector<T>& to_sort, int beg, int end) {
    if (end - beg  >= 1) {
        int mid = beg + (end - beg) / 2;
        sort(to_sort, beg, mid);
        sort(to_sort, mid + 1, end);
        merge(to_sort, beg, end);
    }
}
template<typename T>
void MergeSort<T>::merge(std::vector<T>& to_sort, int beg, int end) {
    int mid = beg + (end - beg) / 2;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    T* Left = new T[n1];
    T* Right = new T[n2];
    for (int i = 0; i < n1; i++)
        Left[i] = to_sort[beg + i];
    for (int j = 0; j < n2; j++)
        Right[j] = to_sort[mid + 1 + j];
    int i = 0,
        j = 0,
        k = beg;
    while (i < n1 && j < n2)
    {
        if ( SortingStrategy<T>::comp(Left[i], Right[j]))
        {
            to_sort[k] = Left[i];
            i++;
        }
        else
        {
            to_sort[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        to_sort[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        to_sort[k] = Right[j];
        j++;
        k++;
    }
}

template<typename T>
void CountSort<T>::sort(std::vector<T>& to_sort, int beg, int end) {

}