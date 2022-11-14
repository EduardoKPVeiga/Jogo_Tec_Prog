#pragma once
#include "Elemento.h"

//Completa
template<class TL> class Lista {
private:
	Elemento<TL>* head;
	Elemento<TL>* tail;
	int length = 0;

public:
	Lista();
	~Lista();

	int getLength() { return length; }

	TL* getItem(int position) {
		Elemento<TL>* temp = head;
		if (position == 0)
			return temp->getItem();
		for (int i = 0; i < position; i++) {
			temp = temp->getNext();
		}
		return temp->getItem();
	}

	void push(TL* item) {
		if (head == nullptr) {
			head = new Elemento<TL>;
			head->setItem(item);
			tail = head;
		}
		else {
			Elemento<TL>* temp = new Elemento<TL>;
			temp->setItem(item);
			tail->setNext(temp);
			tail = temp;
		}
		length++;
	}

	void pop(TL* item) {
		Elemento<TL>* temp = head;
		Elemento<TL>* tempPrev = nullptr;
		while (temp->getItem() != item) {
			tempPrev = temp;
			temp = temp->getNext();
		}
		if (temp == head) {
			head = temp->getNext();
		}
		else if (temp == tail) {
			tempPrev->setNext(nullptr);
			tail = tempPrev;
		}
		else {
			tempPrev->setNext(temp->getNext());
		}
		delete temp;
		length--;
	}
};

template<class TL>
inline Lista<TL>::Lista() {
	head = nullptr;
	tail = nullptr;
	length = 0;
}

template<class TL>
inline Lista<TL>::~Lista() {}
