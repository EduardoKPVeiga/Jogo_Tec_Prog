#pragma once

template <class TE> class Elemento{
private:
	Elemento<TE>* next;
	TE* item;

public:
	Elemento();
	~Elemento();
	void setNext(Elemento<TE>* next) { this->next = next; }
	void setItem(TE* item) { this->item = item; }
	Elemento<TE>* getNext() { return next; }
	TE* getItem() { return item; }
};

template<class TE>
inline Elemento<TE>::Elemento() {
	next = nullptr;
	item = nullptr;
}

template<class TE>
inline Elemento<TE>::~Elemento() {}
