#include "LinkedList.h"
template<typename T>
Node<T>::Node()
{
}
template<typename T>
T Node<T>::getValue()
{
	return data;
}

template<typename T>
void LinkedList<T>::add(T value) {
	if (head == nullptr) {
		head = new Node<T>(value);
		head->next = nullptr;
		tail = head;
	}
	else {
		Node* temp = new Node<T>(value);
		tail->next = temp;
		tail = tail->next;
	}
}

template<typename T>
void LinkedList<T>::add(Node<T>* node) {
	if (head == nullptr) {
		head = node;
		head->next = nullptr;
		tail = head;
	}
	else {
		tail->next = node;
		tail = tail->next;
	}
}

template<typename T>
Node<T>* LinkedList<T>::getElement(int position)
{
	Node<T>* curr = head;
	int counter = 0;
	while (curr != nullptr) {
		if (counter == position) return curr;
		else {
			counter++;
			curr = curr->next;
		}
	}
	return nullptr;
}

template<typename T>
int LinkedList<T>::getPosition(T value) {
	Node<T>* curr = head;
	int counter = 0;
	while (curr != nullptr) {
		if (curr->getValue() == value) return counter;
		else {
			counter++;
			curr = curr->next;
		}
	}
	return -1;
}

template<typename T>
void LinkedList<T>::addElementAtHead(T value) {
	Node<T>* temp = new Node<T>;
	temp->data = value;
	temp->next = head;
	head = temp;
}

template<typename T>
void LinkedList<T>::addElementAtPos(int position, T value) {
	Node<T>* pre = new Node<T>;
	Node<T>* cur = new Node<T>;
	Node<T>* temp = new Node<T>;
	cur = head;
	for (int i = 1; i < position; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->data = value;
	pre->next = temp;
	temp->next = cur;
}

template<typename T>
void LinkedList<T>::deleteElement(int position)
{
	Node<T>* current = new Node<T>;
	Node<T>* previous = new Node<T>;
	current = head;
	for (int i = 1; i < position; i++)
	{
		if (current->next == nullptr) break;
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
}
