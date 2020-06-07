#pragma once

template <typename T>
class LinkedList;
template <typename T>
class Node {
	T data;
	Node* next;
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
	void add(T value);
	void add(Node<T>* node);
	Node<T>* getElement(int position);
	int getPosition(T value);
	void addElementAtHead(T value);
	void addElementAtPos(int position, T value);
	void deleteElement(int position);
	void output();
};


