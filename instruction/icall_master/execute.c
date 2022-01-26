
#include <assert.h>
#include <stdio.h>

#include <macros/LAMBDA.h>

#include <structs/stack.h>
#include <structs/stats.h>

#include <scope/block/struct.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>
#include <misc/vregister_ll/foreach.h>

#include <instruction/frame/struct.h>

#include "struct.h"
#include "execute.h"

void icall_master_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	size_t i = 0;
	struct icall_master_instruction* this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	size_t c = 0;
	size_t n = 0;
	{
		printf("line %4i: ", super->line);
		
		c += printf("%8s %10s", "icall", this->callme->name);
		
		vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			char name[10];
			snprintf(name, 10, "%%vr%u", u);
			c += printf(", %10s", name);
			n++;
		}));
		
		c += printf(" => %%vr%u", this->vr);
		
		while (c < 8 + 1 + 10 + 2 + 10 + 4 + 10 + 2 + 10)
			c++, putchar(' ');
		
		printf(" // (");
		
		i = 0, vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			char value[10];
			
			printf("%%vr%u = %s", u, print_vreg(value, get_vreg(stack, u)));
			
			if (++i < n)
				printf(", ");
		}));
		
		printf(")\n");
		
	}
	#endif
	
	i = 0, vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
		ps[i++] = *get_vreg(stack, u);
	}));
	
	/* push %rip:    */ *stack->rsp.as_pptr-- = super->next;
	/* jump to call: */ *next = this->callme->instruction;
	
	stats->total++;
}























