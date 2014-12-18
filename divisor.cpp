#include "divisor.h"
#include "debug.h"
#include "cmath"
#include <iostream>

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

