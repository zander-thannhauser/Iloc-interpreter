
#include <stdio.h>

#include <structs/stack.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void ret_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct ret_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	{
		printf("line %4u: %8s %10s  %10s    %10s  %10s",
			super->line, "ret", "", "", "", "");
		
		printf(" // (%%vr0 = %p, %%vr1 = %p | ",
			stack->rbp.as_ptr,
			stack->rsp.as_ptr);
		
		fflush(stdout);
		
		assert(stack->rbp.kind == vk_ptr);
		assert(stack->rsp.kind == vk_ptr);
	}
	#endif
	
	/* movq %rrp, %rsp: */  stack->rsp.as_ptr =    stack->rrp.as_ptr;
	/* pop %rbp:        */  stack->rbp.as_ptr = *++stack->rsp.as_pptr;
	/* pop %rrp:        */  stack->rrp.as_ptr = *++stack->rsp.as_pptr;
	
	/* jump (pop %rsp):*/  *next = *++stack->rsp.as_pptr;
	
	#ifdef ASM_VERBOSE
	{
		printf("%%vr0 = %p, %%vr1 = %p",
			stack->rbp.as_ptr,
			stack->rsp.as_ptr);
		
		if (*next)
			printf(", line = %u", (*next)->line);
		
		printf(")\n");
	}
	#endif
	
	stats->total++;
	
}












