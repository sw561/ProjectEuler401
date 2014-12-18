#include <sstream>
#include "divisor.h"
#include "cmath"
#include "cstdio"

// Global variable used to toggle run-time debugging
short unsigned int debug;

#define N 10000000

int main(int argc, char* argv[])
{
	// Debug variable
	if (argc>=3) std::istringstream(argv[2]) >> debug;
	else debug = 0;
//--------------------------------------------------//
	
	// Your program:
	printf("%.0f\n",SIGMA2<N>());

	return 0;
}
