#include "divisor.h"
#include "set.h"
#include "test.h"
#include <iostream>

unsigned short int debug = 0;

bool divisor()
{
	for (int i=1; i<=100; i++){
		List L = divisor(i);
		List K = simple(i);
		if (debug>0){
			L.print();
			K.print();}
		if (L!=K){ return false;}
	}
	return true;
}

template<int N>
int s2()
{
	return SIGMA2(N);
}

int main()
{
	TestSuite s = TestSuite(__FILE__);

	s.test("divisor",&divisor);

	s.test("6",(int)divisor(6).sigma2(),50);

	s.test("SIGMA2 1",&s2<1>,1);
	s.test("SIGMA2 2",&s2<2>,6);
	s.test("SIGMA2 3",&s2<3>,16);
	s.test("SIGMA2 4",&s2<4>,37);
	s.test("SIGMA2 5",&s2<5>,63);
	s.test("SIGMA2 6",&s2<6>,113);
}
