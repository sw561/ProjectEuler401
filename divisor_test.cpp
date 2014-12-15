#include "divisor.h"
#include "set.h"
#include "test.h"

unsigned short int debug = 0;

int main()
{
	for (int i=1; i<20; i++){
		List q = divisor(i);
		q.print();
	}
}
