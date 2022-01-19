
#include <stdio.h>

struct scope;

int parse(FILE* in, struct scope* scope,
	void* globals,
	size_t* out_nregisters);
