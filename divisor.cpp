#include "divisor.h"
#include "cmath"
#include <iostream>
#include "debug.h"

#define IFDEBUG(x) if (debug>0) x;

void divisor(int x, List * cache)
{
	if (!(cache[x].empty())){
		IFDEBUG(std::cout << "Returning from cache." << std::endl)
		return;
	}

	for (int i=2; i<=sqrt(x); i++){
		if (x%i == 0){
			int a = x/i;
			IFDEBUG(std::cout << "Doing a union" << std::endl)
			IFDEBUG(cache[a].print())
			if (cache[a].empty()) divisor(a,cache);
			cache[x].add_list_union(cache[a],cache[a],i);
			return;
		}
	}
	// No non-trivial divisors found
	IFDEBUG(std::cout << "No non-trivial divisors." << std::endl)
	cache[x].insert(1);
	cache[x].insert(x);
}

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
