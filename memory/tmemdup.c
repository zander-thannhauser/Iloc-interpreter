
#include <string.h>

#include "tmalloc.h"
#include "tmemdup.h"

int tmemdup(void** out, void* src, size_t len)
{
	int error = 0;
	ENTER;
	
	error = tmalloc(out, len, NULL);
	
	if (!error)
	{
		memcpy(*out, src, len);
	}
	
	EXIT;
	return error;
}

