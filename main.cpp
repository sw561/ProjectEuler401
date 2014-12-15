#include <iostream>
#include <sstream>
#include <cstdio>
#include "set.h"
#include "parameter.h"

// Global variable used to toggle run-time debugging
short unsigned int debug;

int main(int argc, char* argv[])
{
//	FILE *outfile;
//
//	// Process command line arguments
//	// Output file
// 	if (argc>=2) outfile = fopen(argv[1],"w");
//	else{ std::cout << "No output file specified." << std::endl; throw(0);}
	
	// Debug variable
	if (argc>=3) std::istringstream(argv[2]) >> debug;
	else debug = 0;

	// Parameter file
	if (argc>=4) Parameter::inst(argv[3]);
//--------------------------------------------------//
	
	// Your program:
	const Parameter * param = Parameter::inst();

	List q = List();
	q.insert(param->a);
	q.insert(param->b);
	q.print();

//--------------------------------------------------//
//	fclose(outfile);
	return 0;
}
