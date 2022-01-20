
#include <stddef.h>

#include <structs/vregister.h>

#include "init_stack.h"

int init_stack(void* stack, struct vregister* rs)
{
	int error = 0;
	ENTER;
	
	dpv((unsigned) stack);
	
	#ifdef ASM_VERBOSE
	rs[0].kind   = vk_ptr;
	rs[1].kind   = vk_ptr;
	#endif
	
	// set %rsp:
	{
		rs[1].as_ptr = stack;
	}
	
	// the caller needs to push %rip:
	{
		*rs[1].as_pptr-- = NULL;
	}
	
	EXIT;
	return error;
}

