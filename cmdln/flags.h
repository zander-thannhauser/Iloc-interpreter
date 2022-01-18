
#include <stdbool.h>
#include <stdio.h>

struct cmdln_flags
{
	FILE* in;
	
	bool verbose;
	bool debug;
	
	bool print_stats;
};

