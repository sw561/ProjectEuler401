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
		if (L!=K){
			std::cout << i << std::endl;
			L.print();
			K.print();
			return false;
		}
	}
	return true;
}

int main()
{
	TestSuite s = TestSuite(__FILE__);

	s.test("divisor",&divisor);

	s.test("6",(int)divisor(6).sigma2(),50);

	s.test("SIGMA2 1",&SIGMA2<1>,1.);
	s.test("SIGMA2 2",&SIGMA2<2>,6.);
	s.test("SIGMA2 3",&SIGMA2<3>,16.);
	s.test("SIGMA2 4",&SIGMA2<4>,37.);
	s.test("SIGMA2 5",&SIGMA2<5>,63.);
	s.test("SIGMA2 6",&SIGMA2<6>,113.);
}
