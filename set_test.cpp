#include "set.h"
#include "test.h"
#include <iostream>

short unsigned int debug = 0;

bool compare0()
{
	List L = List();
	L.insert(0);
	L.insert(1);

	List K = List();
	K.insert(0);
	K.insert(1);

	return (L==K);
}
	
bool compare1()
{
	List L = List();
	L.insert(0);
	L.insert(1);

	List K = List();
	K.insert(0);
	K.insert(2);
	
	return (L!=K);
}

bool compare2()
{
	List L = List();
	L.insert(0);
	L.insert(1);

	List K = List();
	K.insert(0);

	return (L!=K && K!=L);
}

bool compare3()
{
	List L = List();
	L.insert(2);
	L.insert(1);

	unsigned int x[2]={1,2};
	return (L==x);
}

bool test1()
{
	List L = List();

	L.insert(2);
	L.insert(5);
	L.insert(3);
	L.insert(124);
	L.insert(19);
	L.insert(3);
	if (debug>0) L.print();

	List L2 = List();
	int ans[5] = {2,3,5,19,124};
	for (int i=0; i<5; i++) L2.insert(ans[i]);

	return L==L2;
}

bool uniontest2()
{
	List L = List();

	L.insert(2);
	L.insert(5);
	L.insert(3);
	L.insert(124);
	L.insert(19);
	L.insert(3);
	if (debug>0) L.print();
	
	List L3 = List();
	L3.add_list_union(L,2);

	unsigned int ans[10] = {2,3,4,5,6,10,19,38,124,248};
	return L3==ans;
}

int sigma2test()
{
	List L = List();

	L.insert(2);
	L.insert(5);
	L.insert(3);

	return L.sigma2();
}
	

int main()
{
	TestSuite s = TestSuite(__FILE__);

	s.test("Compare 0",&compare0);
	s.test("Compare 1",&compare1);
	s.test("Compare 2",&compare2);
	s.test("Compare 3",&compare3);
	s.test("Test 1",&test1);
	s.test("Union test 2",&uniontest2);
	s.test("sigma2",&sigma2test,38);
}
