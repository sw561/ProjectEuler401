#ifndef SET_H
#define SET_H

struct Node {
	long unsigned int data;
	long unsigned int data2;
	Node * next;
	Node * prev;
};

// This is an ordered unique list designed
// for efficient unioning with another list
class List {

	public:
		List();
		List(const List&);
		~List();
		void insert(const unsigned long int);
		void insert(const unsigned long int, const unsigned long int);
		void print()const;
		bool empty()const;

		// Using the same list
		void add_list_union(const List& L1, unsigned long int m);

		// sigma2 returns sum of squares of data
		long unsigned int sigma2()const;

		// This function is unsafe in the case 
		// where the array is shorter than the length of the list
		// The function will attempt to read memory beyond the array end
		bool operator==(const unsigned int *);
		// This function is safe for lists of different lengths (it will return false)
		bool operator==(const List&);

		bool operator!=(const unsigned int *);
		bool operator!=(const List&);
	
	private:
		Node * head;
		Node * tail;
};

#endif
