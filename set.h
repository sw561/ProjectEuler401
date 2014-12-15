#ifndef SET_H
#define SET_H

#include <stdexcept>

struct Node {
	int data;
	Node * next;
	Node * prev;
};

// This is an ordered unique list designed
// for efficient unioning with another list
// It keeps a record of the number of each data instance.
class List {
	friend class Iterator;
	public:
		List();
		List(const List&);
		~List();
		void insert(const int);
		void print()const;
	private:
		Node * head;
		Node * tail;
};

class Iterator{
	friend class List;
	friend List list_union(const List&, const List&);
	public:
		Iterator(const List&);
		int get()const;
		Node * operator++();
		bool finished;
	private:
		Node * iter;
};

List list_union(const List&, const List&);

bool compare(const List&, const int *);

bool compare(const List&, const List&);

class OutOfBounds : public std::exception{
	public:
		virtual const char * what() const throw(){
			return "Out of bounds";}
};

#endif
