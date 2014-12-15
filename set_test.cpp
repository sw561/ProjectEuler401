#include "set.h"
#include "test.h"
#include "iostream"

short unsigned int debug = 0;

bool test1()
{
	List L = List();

	L.insert(2);
	L.insert(5);
	L.insert(3);
	L.insert(-124);
	L.insert(-19);
	L.insert(3);
	if (debug>0) L.print();

	int ans[5] = {-124,-19,2,3,5};
	
	return compare(L,ans);
}

bool uniontest()
{
	List L = List();

	L.insert(2);
	L.insert(5);
	L.insert(3);
	L.insert(-124);
	L.insert(-19);
	L.insert(3);

	List L2 = List();
	L2.insert(1);
	L2.insert(-5);
	L2.insert(3);

	List L3 = list_union(L,L2);

	int ans[7] = {-124,-19,-5,1,2,3,5};

	return compare(L3,ans);
}

bool copyconstructor()
{
	List L = List();

	L.insert(3);
	L.insert(-2);

	List L2 = L;
	return compare(L,L2);
}

int main()
{
	TestSuite s = TestSuite(__FILE__);

	s.test("Test 1",&test1);
	s.test("Test 2",&uniontest);
	s.test("Copy constructor",&copyconstructor);
}
