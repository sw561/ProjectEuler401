#include "set.h"
#include "debug.h"
#include <iostream>

#ifdef DEBUG
//#define IFDEBUG(x) if (debug>0) x;
//#else
#define IFDEBUG(x)
#endif

List::List()
{
	head = 0;
	tail = 0;
}

List::List(const int x)
{
	Node * q = new Node;
	q->data = x;
	IFDEBUG(std::cout << "Inserting first Node " << x << std::endl)
	q->next = 0;
	q->prev = 0;

	head = q;
	tail = q;
}

List::List(const List& L)
{
	head = 0;
	tail = 0;
	for (Node * iter = L.head; iter; iter=iter->next){
		insert(iter->data);
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
	// x is first node
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
		return;
	}
		
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
		IFDEBUG(std::cout << "Inserting Node at the front " << x << std::endl)
		q->next = head;
		q->prev = 0;
		head->prev = q;

		head = q;
		return;
	}

	// x needs to be inserted within the list
	IFDEBUG(std::cout << "Inserting Node in the middle " << x << std::endl)
	Node * iter = head;
	while (x > iter->data) iter=iter->next;
	
	// If x is already in the List
	if (x == iter->data){
		IFDEBUG(std::cout << "Node already present " << x << std::endl)
		return;
	}

	// Insert q in front of i.
	Node * q = new Node;
	q->data = x;
	q->next = iter;
	q->prev = iter->prev;
	
	iter->prev->next = q;
	iter->prev = q;
}

void List::print()const
{
	std::cout << "List: ";
	for (Node * iter = head; iter; iter=iter->next){
		std::cout << iter->data << " ";
	}
	std::cout << std::endl;
}

bool List::empty()const { if (head==0) return true; return false;}

void List::add_list_union(const List& L1, const List& L2, int m)
{
	Node * i1 = L1.head;
	Node * i2 = L2.head;

	while (i1 || i2){
		if (!(i1)){
			insert(i2->data*m);
			i2 = i2->next;
			continue;
		}
		if (!(i2)){
			insert(i1->data);
			i1 = i1->next;
			continue;
		}

		IFDEBUG(std::cout << i1->data << " " << i2->data*m << std::endl)

		if (i1->data==i2->data*m){
			insert(i1->data);
			i1 = i1->next;
			i2 = i2->next;
		}

		else if (i1->data < i2->data*m){
			insert(i1->data);
			i1 = i1->next;
		}
		else if (i2->data*m < i1->data){
			insert(i2->data*m);
			i2 = i2->next;
		}
	}
}

bool List::operator==(const int * x)
{
	int j = 0;
	for ( Node * i = head; i; i=i->next, j++){
		if (i->data != x[j]) return false;
	}
	return true;
}

bool List::operator==(const List& L)
{
	Node * i = head;
	Node * j = L.head;
	for (; i&&j; j=j->next, i=i->next){
		if (j->data != i->data) return false;
	}
	// The lists are not of the same length
	if (i||j) return false;
	return true;
}

bool List::operator!=(const int * x) {return !((*this)==x);}

bool List::operator!=(const List& L) {return !((*this)==L);}
