#pragma once
#include "Node.h";
#include <iostream>

using namespace std;

template <class T>
class Lista
{
public:
	Lista();
	~Lista();

private:
	Node<T> *start;
	int tamanho = 0;
	Lista(int tamanho, Node<T> *start);

public:
	void add(T *element);
	int size();
	bool isEmpty();
	int indexOf(T *element);
	bool contains(T *element);
	void clear();
	T get(int index);
	int lastindexOf(T *element);
	void add(int index, T *element);
	void remove(T *element);
	void remove(int index);
	T getHead();
	T getTail();
	bool isHead(T *element);
	bool isTail(T *element);
	T Next(T *element);
	Lista *separa_lista(Lista *lista, int n);
	void print(Lista<T> lista);

};

template<class T>
Lista<T>::Lista() {

}

template <class T>
Lista<T> ::Lista<T>(int tamanho, Node<T> *start) {
	this->tamanho = tamanho;
	this->Node<T> *start = Node<T> *start;
}

template <class T>
void Lista <T>::add(T *element) {
	if (start == nullptr) {
		Node novoNo(element);
		*start = novoNo;
		Node noAntes(element);
		noAntes = start;
		Node noFinal(element);
		noFinal = getTail();
		noFinal->proxno = start->proxno;
		noAntes->proxno = noFinal;

		tamanho++;
	}
	else {
		if (tamanho == 1) {
			if (start->element <= *element) {
				Node proxNo(*element);
				Node* pont = *proxNo;
				start->proxNo = *pont;
				Node noAnterior(*element);
				noAnterior = start->proxNo;
				Node *ptrAntes = *proxNo;

				start->proxno = noAnterior;
				*proxNo = *ptrAntes;

				tamanho++;
			}
			else {
				Node newstart(*element);
				Node newAnterior(*element);
				newstart->proxNo = start;
				start = newstart;
				newAnterior = start;
				start->proxno = newAnterior;
				tamanho++;
			}
		}
		else {
			Node outroNo(element);
			Node noAtual = start;
			while (noAtual->proxNo != nullptr) {
				if ((noAtual->element <= outroNo->element) && (noAtual->proxNo->element > outroNo->element)) {
					Node ultimoNo = noAtual;
					Node *prtd = ultimoNo;
					noAtual->proximoNo = prtd;

					tamanho++;
				}
				else {
					noAtual = &noAtual->proxNo;
				}
			}
		}
	}
}

template <class T>
int Lista<T>::size() {
	return tamanho;
}

template<class T>
bool Lista<T>::isEmpty()
{
	if (tamanho == 0) {
		return true;
	}
	return false;

}

template<class T>
int Lista<T>::indexOf(T *element) {
	Node<T> noAtual = start;
	int index = 0;
	while (noAtual != nullptr) {
		if (element == noAtual->element) {
			return index;
		}
		index++;
	}
	return -1;
}

template<class T>
bool Lista<T> ::contains(T *element) {
	int index = this->indexOf(element);
	if (index != -1) {
		return true;
	}
	return false;
}

template<class  T>
void Lista<T>::clear() {
	start = nullptr;
	tamanho = 0;
}

template<class T>
int Lista<T>::lastindexOf(T *element) {
	Node<T> noAtual = start;
	int index = 0, last = -1;
	while (noAtual != nullptr) {
		if (element == noAtual->element) {
			last = index;
		}
		noAtual = noAtual->proxno;
		index++;
	}
	return last;
}

template<class T>
T Lista<T>::get(int index) {
	Node<T> noAtual = start;
	int indexAtual = 0;
	while (noAtual != nullptr) {
		if (index == indexAtual) {
			return noAtual->element;
		}
		else {
			noAtual = noAtual->proxno;
		}
		indexAtual++;
	}
	return nullptr;
}

template <class T>
void Lista<T>::add(int index, T *element) {
	Node noAnterior = start;
	Node noAtual = start->proxno;
	int indexAtual = 0;

	if (index == 0) {
		Node novoNo(element);
		novoNo->proxno = noAnterior;
		start = novoNo;
		tamanho++;
		return;
	}

	while (noAnterior != nullptr) {
		if (index == indexAtual) {
			Node novoNo(element);
			noAnterior->proxno = *novoNo;
			novoNo->proxno = *noAtual;
		}
		else {
			noAnterior = noAtual;
			noAtual = noAtual->proxno;
		}
		indexAtual++;
	}
	tamanho++;
}

template <class T>
void Lista<T>::remove(T *element) {
	Node<T> noAtual = start;
	int indexAtual = 0;
	while (noAtual != nullptr) {
		if (noAtual->*element == *element) {
			noAtual = noAtual->proxno->proxno;
		}
		else {
			noAtual = noAtual->proxno;
		}
		indexAtual++;
	}
	return nullptr;
}


template <class T>
void Lista<T>::remove(int index) {
	Node<T> noAtual = start;
	int indexAtual = 0;
	while (noAtual != nullptr) {
		if (index == indexAtual) {
			noAtual = noAtual->proxno->proxno;
		}
		else {
			noAtual = noAtual->proxno;
		}
	}
	indexAtual++;
}

template <class T>
T Lista<T>::getHead() {
	return start->element;
}

template<class T>
T Lista<T>::getTail() {
	Node<T> noAtual = start;
	if (noAtual == nullptr)
	{
		return noAtual->element;
	}
	else {
		while (noAtual != nullptr)
		{
			if (noAtual == nullptr)
			{
				return noAtual->element;
			}
			else {
				noAtual = noAtual->proxno;
			}
		}
	}
}

template<class T>
bool Lista<T>::isHead(T *element) {
	if (start->element == element) {
		return true;
	}
	return false;
}

template<class T>
bool Lista<T>::isTail(T *element) {
	Node *noAtual = start;
	while (!noAtual == nullptr) {
		if (noAtual->proxno == nullptr) {
			if (noAtual->element == element) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			noAtual = noAtual->proxno;
		}
	}
}

template<class T>
T Lista<T>::Next(T *element) {
	Node *noAtual = start;
	while (!noAtual == nullptr) {
		if (noAtual->element == element) {
			return noAtual->proxno->element;
		}
		else {
			noAtual = noAtual->proxno;
		}
	}
}

template<class T>
Lista<T> * Lista<T>::separa_lista(Lista<T> * lista, int n)
{
	Node<T> noAtual = *start;
	int indexAchado = lista->indexOf(n);
	int index = 0;
	while (noAtual != nullptr) {
		if (index == indexAchado) {
			Lista<T> NewLista(((tamanho - indexAchado) + 1), noAtual->proxNo);
			tamanho -= ((tamanho - indexAchado) + 1);
			noAtual->proxno = nullptr;
			return NewLista;
		}
		else {
			noAtual = noAtual->proxno;
		}
		index++;
	}
	return nullptr;
}

/*template <class T>
void Lista<T>::print(Lista<T> lista) {
	Node *noAtual = start;
	while (!noAtual == nullptr) {
		if (!noAtual == nullptr) {
			cout << "{";
			cout << &noAtual;
			noAtual = noAtual->proxno;
		}
		else {
			cout << "}";
		}
	}
*/





