#include "divisor.h"
#include "debug.h"
#include "cmath"
#include <iostream>

#ifdef DEBUG
//#define IFDEBUG(x) if (debug>0) x;
//#else
#define IFDEBUG(x)
#endif

#define CACHE_SIZE 15000000

List simple(int x)
{
	List q = List();

	for (int i=1; i<=x/2; i++){
		if (x%i==0){
			q.insert(i);
			q.insert(x);
		}
	}
	if (x==1) q.insert(1);
	return q;
}

List divisor(const unsigned long int x)
{
	static List cache[CACHE_SIZE] = {List()};
	if (x<CACHE_SIZE){
		unsigned long int index = x;
		
		if (!cache[index].empty()){
			IFDEBUG(std::cout << "Returning from cache " << x << std::endl)
			return cache[index];
		}
		for (unsigned long int i = 2; i<=sqrt(x); i++){
			if (x%i == 0){
				unsigned long int a = x/i;
				cache[index].add_list_union(divisor(a),i);
				return cache[index];
			}
		}
		cache[index].insert(1);
		cache[index].insert(x);
		return cache[index];
	}

	List L = List();
	for (unsigned long int i = 2; i<=sqrt(x); i++){
		if (x%i == 0){
			unsigned long int a = x/i;
			L.add_list_union(divisor(a),i);
			return L;
		}
	}
	L.insert(1);
	L.insert(x);
	return L;
}

double SIGMA2(const unsigned long int N)
{
	double s = 0;
	for (unsigned long int i=1; i<=N; i++){
		s += divisor(i).sigma2();
	}
	return s;
}
