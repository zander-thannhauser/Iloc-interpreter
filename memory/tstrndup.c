
#include <string.h>

#include "tmalloc.h"
#include "tinc.h"
#include "tfree.h"

#include "tstrndup.h"

int tstrndup(char** out, const char* string, size_t n)
{
	int error = 0;
	size_t len;
	char* new = NULL;
	
	len = strnlen(string, n);
	
	error = tmalloc((void**) &new, len + 1, NULL);
	
	if (!error)
	{
		memcpy(new, string, len + 1);
		
		*out = new;
	}
	
	return error;
}

