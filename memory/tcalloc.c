
#include <string.h>

#include <memory/tmalloc.h>

#include "tcalloc.h"

int tcalloc(
	void** ptr, 
	size_t nmemb, size_t size)
{
	int error = 0;
	size_t len = nmemb * size;
	ENTER;
	
	error = tmalloc(ptr, len, NULL);
	
	if (!error)
	{
		dpv(len);
		dpv(*ptr);
		memset(*ptr, 0, len);
	}
	
	EXIT;
	return error;
}


