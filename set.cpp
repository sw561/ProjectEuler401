#include "set.h"
#include "debug.h"
#include <iostream>

#ifdef DEBUG
#define IFDEBUG(x) if (debug>0) x;
#else
#define IFDEBUG(x)
#endif

List::List()
{
	head = 0;
	tail = 0;
}

// Copy constructor
List::List(const List& L)
{
	head = 0;
	tail = 0;
	for (Iterator i = Iterator(L); !i.finished; ++i){
		this->insert(i.get());
	}
}

List::~List()
{
	while (head != 0){
		Node * temp = head->next;
		IFDEBUG(std::cout << "Deleting " << head->data << std::endl)
		delete head;
		head = temp;
	}
}

void List::insert(const int x)
{
	// x is the first node
	if (head==0){
		Node * q = new Node;
		q->data = x;
		IFDEBUG(std::cout << "Inserting first Node " << x << std::endl)
		q->next = 0;
		q->prev = 0;

		head = q;
		tail = q;
		return;
	}

	// x is equal to first or last node
	if (x == tail->data || x == head->data){
		IFDEBUG(std::cout << "Node already present " << x << std::endl)
		return;}
		
	// x is larger than last node
	if (x > tail->data){
		Node * q = new Node;
		q->data = x;
		IFDEBUG(std::cout << "Inserting Node at the back " << x << std::endl)
		q->prev = tail;
		q->next = 0;

		tail->next = q;
		tail = q;
		return;
	}

	// x is smaller than first node
	if (x < head->data){
		Node * q = new Node;
		q->data = x;
		IFDEBUG(std::cout << "Inserting Node on the front " << x << std::endl)
		q->next = head;
		q->prev = 0;

		head->prev = q;
		head = q;
		return;
	}

	// x needs to be inserted within the list
	IFDEBUG(std::cout << "Inserting Node in the middle " << x << std::endl)
	Iterator i = Iterator(*this);
	while (x > i.get()) ++i;
	
	// If x is already in the List
	if (x == i.get()){
		IFDEBUG(std::cout << "Node already present " << x << std::endl)
		return;
	}

	// Insert q in front of i.
	Node * q = new Node;
	q->data = x;
	q->next = i.iter;
	q->prev = i.iter->prev;
	
	i.iter->prev->next = q;
	i.iter->prev = q;
}

void List::print()const
{
	for (Iterator i = Iterator(*this); !i.finished; ++i){
		std::cout << i.get() << " ";
	}
	std::cout << std::endl;
}

Iterator::Iterator(const List& L)
{
	iter = L.head;
	if (iter) finished = false;
	else finished = true;
}

int Iterator::get()const
{
	if (!iter) throw OutOfBounds();
	return iter->data;
}

Node * Iterator::operator++()
{
	if (iter==0){
		finished = true;
		return iter;}
	iter = iter->next;
	if (iter==0) finished = true;
	return iter;
}

List list_union(const List& L1, const List& L2)
{
	List L = List();
	Iterator i1 = Iterator(L1);
	Iterator i2 = Iterator(L2);

	while (!i1.finished || !i2.finished){
		if (i1.finished){
			L.insert(i2.get());
			++i2;
			continue;
		}
		if (i2.finished){
			L.insert(i1.get());
			++i1;
			continue;
		}

		IFDEBUG(std::cout << i1.get() << " " << i2.get() << std::endl)

		if (i1.get()==i2.get()){
			L.insert(i1.get());
			++i1;
			++i2;
		}

		else if (i1.get() < i2.get()){
			L.insert(i1.get());
			++i1;
		}
		else if (i2.get() < i1.get()){
			L.insert(i2.get());
			++i2;
		}
	}
	return L;
}

bool compare(const List& L, const int * x)
{
	int j = 0;
	for (Iterator i = Iterator(L); !i.finished; ++i,++j){
		if (i.get()!=x[j]){
			IFDEBUG(std::cout << "Element " << j+1 << " was " << i.get() << ". Expected " << x[j] << std::endl)
			return false;}
	}
	return true;
}

bool compare(const List& L1, const List& L2)
{
	Iterator i = Iterator(L1);
	Iterator j = Iterator(L2);
	while (!i.finished){
		if (i.get()!=j.get()) return false;
		++i;
		++j;
	}

	if (!j.finished) return false;
	return true;
}
