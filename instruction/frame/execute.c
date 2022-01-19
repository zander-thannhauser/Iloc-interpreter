
#include <stdio.h>

#include <macros/LAMBDA.h>

#include <structs/vregister.h>

#include <misc/vregister_ll/foreach.h>

#include "struct.h"
#include "execute.h"

void frame_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	union vregister* ps,
	struct instruction** next)
{
	size_t i = 0, n = 0;
	struct frame_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		printf("line %4u: %8s %10s, %10zu", super->line,
			".frame", this->name, this->frame_size);
		
		vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			printf(", %%vr%u", u);
			n++;
		}));
	}
	
	/* pushq %rbp:      */ *rs[1].as_pptr-- = rs[0].as_ptr;
	/* movq %rsp, %rbp: */  rs[0].as_ptr    = rs[1].as_ptr;
	/* subq fs, %rsp:   */  rs[1].as_int   -= this->frame_size;
	
	// copy parameters over:
	{
		i = 0, vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			rs[u] = ps[i++];
		}));
	}
	
	if (debug)
	{
		printf(" // (%%vr0 = %p, %%vr1 = %p",
			rs[0].as_ptr, rs[1].as_ptr);
		
		vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			printf(", %%vr%u = %i", u, rs[u].as_int);
		}));
		
		printf(")\n");
	}
	
	*next = super->next;
}


















