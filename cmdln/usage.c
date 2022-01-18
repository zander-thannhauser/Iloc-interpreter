
#include <stdio.h>

#include <debug.h>

#include <defines/argv0.h>

#include "usage.h"

void usage()
{
	ENTER;
	
	printf("usage: %s [-dv] -i <input-file>\n", argv0);
	
	EXIT;
}

