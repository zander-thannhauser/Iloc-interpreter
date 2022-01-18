
#include <stdio.h>

struct scope;

int parse(FILE* in, struct scope* scope,
	size_t* out_nregisters);
