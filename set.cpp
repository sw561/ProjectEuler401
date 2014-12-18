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

List::List(const List& L)
{
	head = 0;
	tail = 0;
	for (Node * iter = L.head; iter; iter=iter->next){
		insert(iter->data,iter->data2);
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

bool List::empty()const
{
	Node * iter = head;
	if (iter) return false;
	return true;
}

void List::insert(const long unsigned int x)
{
	insert(x,x*x);
}

void List::insert(const long unsigned int x, const long unsigned int x2)
{
	// x is first node
	if (head==0){
		Node * q = new Node;
		q->data = x;
		q->data2 = x2;
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
		q->data2 = x2;
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
		q->data2 = x2;
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
	q->data2 = x2;
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
	for (Node * iter = head; iter; iter=iter->next){
		std::cout << iter->data2 << " ";
	}
	std::cout << std::endl;
}

void List::add_list_union(const List& L, long unsigned int m)
{
	long unsigned int m2 = m*m;

	Node * i1 = L.head;
	Node * i2 = L.head;

	while (i1 || i2){
		if (!(i1)){
			insert(i2->data*m,i2->data2*m2);
			i2 = i2->next;
			continue;
		}
		if (!(i2)){
			insert(i1->data,i1->data2);
			i1 = i1->next;
			continue;
		}

		IFDEBUG(std::cout << i1->data << " " << i2->data*m << std::endl)

		if (i1->data==i2->data*m){
			insert(i1->data,i1->data2);
			i1 = i1->next;
			i2 = i2->next;
		}

		else if (i1->data < i2->data*m){
			insert(i1->data,i1->data2);
			i1 = i1->next;
		}
		else if (i2->data*m < i1->data){
			insert(i2->data*m,i2->data2*m2);
			i2 = i2->next;
		}
	}
}

long unsigned int List::sigma2()const
{
	long unsigned int s = 0;
	for (Node * iter = head; iter; iter=iter->next){
		s += iter->data2;
	}
	return s;
}

bool List::operator==(const unsigned int * x)
{
	int j = 0;
	for (Node * i = head; i; i=i->next, j++){
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

bool List::operator!=(const unsigned int * x) {return !((*this)==x);}

bool List::operator!=(const List& L) {return !((*this)==L);}
