
#include <structs/vregister.h>

#include "init_stack.h"

int init_stack(void* stack, union vregister* rs)
{
	int error = 0;
	ENTER;
	
	// set %rsp:
	{
		rs[1].as_int = (int64_t) stack;
	}
	
	// the caller needs to push %rip:
	{
		int32_t* rsp = (int32_t*) (int64_t) rs[1].as_int;
		*rsp = 0;
		rs[1].as_int -= 4;
	}
	
	EXIT;
	return error;
}

