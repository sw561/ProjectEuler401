#include "set.h"
#include "test.h"
#include "iostream"

short unsigned int debug = 0;

bool compare0()
{
	List L = List();
	L.insert(0);
	L.insert(1);

	List K = List();
	K.insert(0);
	K.insert(1);

	return (compare(L,K) && compare(K,L));
}
	
bool compare1()
{
	List L = List();
	L.insert(0);
	L.insert(1);

	List K = List();
	K.insert(0);
	K.insert(2);
	
	return (!compare(L,K) && !compare(K,L));
}

bool compare2()
{
	List L = List();
	L.insert(0);
	L.insert(1);

	List K = List();
	K.insert(0);

	return (!compare(L,K) && !compare(K,L));
}

bool compare3()
{
	List L = List();
	L.insert(2);
	L.insert(-1);

	int x[2]={-1,2};
	return (compare(L,x) && compare(x,L));
}

bool compare4()
{
	List L = List();
	L.insert(2);
	L.insert(-1);

	int x[1]={0};
	return (!compare(L,x) && !compare(x,L));
}


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
	if (debug>0) L.print();

	//List L2 = L;
	List L2 = List();
	L2.insert(-2);
	L2.insert(3);
	if (debug>0) L2.print();
	return compare(L,L2);
}

int main()
{
	TestSuite s = TestSuite(__FILE__);

	s.test("Compare 0",&compare0);
	s.test("Compare 1",&compare1);
	s.test("Compare 2",&compare2);
	s.test("Compare 3",&compare3);
	s.test("Compare 4",&compare4);
	s.test("Test 1",&test1);
	s.test("Union test",&uniontest);
	s.test("Copy constructor",&copyconstructor);
}
