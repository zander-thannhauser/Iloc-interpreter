
#include <stdio.h>

#include <defines/argv0.h>

#include "usage.h"

void usage()
{
	ENTER;
	
	printf("usage: %s [-s] -i <input-file>\n", argv0);
	
	EXIT;
}

