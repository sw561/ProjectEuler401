#ifndef SET_H
#define SET_H

struct Node {
	int data;
	Node * next;
	Node * prev;
};

// This is an ordered unique list designed
// for efficient unioning with another list
class List {

	public:
		List();
		List(const int);
		List(const List&);
		~List();
		void insert(const int);
		// Efficiently add the union of L1 with m * entries of L2
		void add_list_union(const List& L1, const List& L2, int m);
		void print()const;
		bool empty()const;

		// This function is unsafe in the case 
		// where the array is shorter than the length
		// The function will attempt to read memory beyond the array end
		bool operator==(const int *);
		// This function is safe to lists of different lengths (it will return false)
		bool operator==(const List&);

		bool operator!=(const int *);
		bool operator!=(const List&);
	
	private:
		Node * head;
		Node * tail;
};

#endif
