#include "divisor.h"
#include "set.h"
#include "test.h"

unsigned short int debug = 0;

bool test1()
{
	List cache[1000] = {List()};
	divisor(360,cache);
	if (debug>0) cache[360].print();

	List L2 = simple(360);
	if (debug>0) L2.print();
	
	return cache[360]==simple(360);
}

bool test2()
{
	List cache[1000] = {List()};

	for (int i=1; i<1000; i++)
	{
		divisor(i,cache);
		if (cache[i]!=simple(i)){
			if (debug>0) std::cout << "Failure for " << i << std::endl;
			return false;
		}
	}
	return true;
}

int main()
{
	TestSuite s = TestSuite(__FILE__);

	s.test("360",&test1);
	s.test("All",&test2);

}
