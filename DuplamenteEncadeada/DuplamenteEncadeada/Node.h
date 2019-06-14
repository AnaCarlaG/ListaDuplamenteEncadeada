#pragma once
template <class T>
class Node
{
public:
	Node(T *element);
	~Node();

public:
	Node *proxno;
	T *element;

};

template <class T>
Node<T> ::Node(T *element) {
	this->element = element;
}
