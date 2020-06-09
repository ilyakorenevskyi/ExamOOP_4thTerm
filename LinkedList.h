#ifndef LINKEDLIST_H
#define LINKEDLIST_H
 // LINKEDLIST.H

#include <vector>
//template <typename T, typename U>
//class Iterator {
//public:
//    typedef typename std::vector<T>::iterator iter_type;
//    Iterator(U* p_data, bool reverse = false) : m_p_data_(p_data) {
//        m_it_ = m_p_data_->m_data_.begin();
//    }
//
//    void First() {
//        m_it_ = m_p_data_->m_data_.begin();
//    }
//
//    void Next() {
//        m_it_++;
//    }
//
//    bool IsDone() {
//        return (m_it_ == m_p_data_->m_data_.end());
//    }
//
//    iter_type Current() {
//        return m_it_;
//    }
//
//private:
//    U* m_p_data_;
//    iter_type m_it_;
//};
template <typename T>
class LinkedList;

template <typename T>
class Node {
	T data;
	Node<T>* next;
public:
	Node();
	Node(T value) :data(value) {}
	T getValue();
	friend class LinkedList<T>;

};

template <typename T>
class LinkedList{
	Node<T>* head;
	Node<T>* tail;
 
public:
	LinkedList() :head(nullptr), tail(nullptr) {};
	LinkedList(std::vector<T>);
	void add(T value);
	void add(Node<T>* node);
	Node<T>* getElement(int position);
	int getPosition(T value);
	void addElementAtHead(T value);
	std::vector<T> toVector();
	void addElementAtPos(int position, T value);
	void deleteElement(int position);
	void output();
};

#include "LinkedList.cpp"
#endif

