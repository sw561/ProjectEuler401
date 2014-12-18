#ifndef DIVISOR_H
#define DIVISOR_H

#include "set.h"

// Simple function for verifying answers
List simple(int x);

List divisor(unsigned long int x);

template<unsigned long int N>
double SIGMA2()
{
	double s = 0;
	for (unsigned long int i=1; i<=N; i++){
		s += divisor(i).sigma2();
	}
	return s;
}

#endif
