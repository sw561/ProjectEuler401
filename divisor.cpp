#include "divisor.h"
#include "cmath"

List divisor(int x)
{
	List q = List();
	for (int i=1; i<=sqrt(x); i++){
		if (x%i == 0){
			q.insert(i);
			q.insert(x/i);
		}
	}

	return q;
}
