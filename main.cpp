#include <sstream>
#include <iostream>
#include "divisor.h"
#include "cstdio"
#include "parameter.h"
#include "cmath"

// Global variable used to toggle run-time debugging
short unsigned int debug;

int main(int argc, char* argv[])
{
	FILE *outfile;

	// Process command line arguments
	// Output file
 	if (argc>=2) outfile = fopen(argv[1],"w");
	else{ std::cout << "No output file specified." << std::endl; throw(0);}
	
	// Debug variable
	if (argc>=3) std::istringstream(argv[2]) >> debug;
	else debug = 0;

	// Parameter file
	if (argc>=4) Parameter::inst(argv[3]);
	
	// Debug variable
	if (argc>=3) std::istringstream(argv[2]) >> debug;
	else debug = 0;
//--------------------------------------------------//
	
	// Your program:
	const Parameter * param = Parameter::inst();
	unsigned long int N = pow(10,param->n);
	fprintf(outfile,"%ld %.0f\n",N,SIGMA2(N));

	fclose(outfile);
	return 0;
}
