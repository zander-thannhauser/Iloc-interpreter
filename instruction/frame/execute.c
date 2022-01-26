
#include <stdio.h>

#include <macros/LAMBDA.h>

#include <structs/stack.h>

#include <misc/vregister_ll/foreach.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void frame_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	size_t i = 0;
	struct frame_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	size_t c = 0;
	{
		printf("line %4u: ", super->line);
		
		c += printf("%8s %10s, %10zu", ".frame", this->name, this->frame_size);
		
		vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			c += printf(", %%vr%u", u);
		}));
		
		while (c < 8 + 1 + 10 + 2 + 10 + 4 + 10 + 2 + 10)
			c++, putchar(' ');
		
		printf(" // (");
		
		printf("%%vr0 = %p, %%vr1 = %p", stack->rbp.as_ptr, stack->rsp.as_ptr);
		
		printf(" | ");
		
		fflush(stdout);
	}
	#endif
	
	/* pushq %rrp:      */ *stack->rsp.as_pptr-- = stack->rrp.as_ptr;
	/* pushq %rbp:      */ *stack->rsp.as_pptr-- = stack->rbp.as_ptr;
	/* movq %rsp, %rrp: */  stack->rrp.as_ptr    = stack->rsp.as_ptr;
	/* subq nr, %rsp:   */  stack->rsp.as_rptr  -= this->nregs;
	/* movq %rsp, %rbp: */  stack->rbp.as_ptr    = stack->rsp.as_ptr;
	/* subq fs, %rsp:   */  stack->rsp.as_int   -= this->frame_size;
	
	// copy parameters over:
	{
		i = 0, vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			*get_vreg(stack, u) = ps[i++];
		}));
	}
	
	#ifdef ASM_VERBOSE
	{
		printf("%%vr0 = %p, %%vr1 = %p", stack->rbp.as_ptr, stack->rsp.as_ptr);
		
		vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			char value[10];
			printf(", %%vr%u = %s", u, print_vreg(value, get_vreg(stack, u)));
		}));
		
		printf(")\n");
	}
	#endif
	
	*next = super->next;
}


















