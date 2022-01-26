
#include <assert.h>
#include <stdio.h>

#include <structs/stack.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>

#include "struct.h"
#include "execute.h"

void iret_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct iret_instruction* const this = (typeof(this)) super;
	
	struct vregister* vr = get_vreg(stack, this->vr);
	
	#ifdef ASM_VERBOSE
	char name[10];
	{
		snprintf(name, 10, "%%vr%u", this->vr);
		
		printf("line %4u: %8s %10s  %10s    %10s  %10s",
			super->line, "iret", name, "", "", "");
		
		printf(" // (%%vr0 = %p, %%vr1 = %p, retval = %i | ",
			stack->rbp.as_ptr,
			stack->rsp.as_ptr,
			vr->as_int);
		
		fflush(stdout);
		
		assert(stack->rbp.kind == vk_ptr);
		assert(stack->rsp.kind == vk_ptr);
		
		assert(vr->kind == vk_int);
	}
	#endif
	
	ps[0].as_int = vr->as_int;
	
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












