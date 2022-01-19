
#include <defines/INITIAL_STACK_SIZE.h>

#include <structs/vregister.h>

#include "mmap_stack.h"

int mmap_stack(void** out)
{
	int error = 0;
	void* stack;
	ENTER;
	
	dpv(INITIAL_STACK_SIZE);
	
	stack = mmap(
		/* void    *addr: */ NULL,
		/* size_t length: */ INITIAL_STACK_SIZE,
		/* int      prot: */ PROT_READ | PROT_WRITE,
		/* int     flags: */ MAP_PRIVATE | MAP_32BIT | MAP_STACK | MAP_GROWSDOWN | MAP_ANONYMOUS,
		/* int        fd:*/ -1,
		/* off_t  offset:*/  0);
	
	if (stack == (void*) -1)
	{
		fprintf(stderr, "%s: mmap(): %m\n", argv0);
		error = e_syscall_failed;
	}
	else
	{
		dpv(stack);
		*out = stack;
	}
	
	EXIT;
	return error;
}












