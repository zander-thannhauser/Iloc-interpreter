
#include <stdio.h>

#include <macros/LAMBDA.h>

#include <structs/vregister.h>

#include <misc/vregister_ll/foreach.h>

#ifdef ASM_VERBOSE
#include <misc/print_vreg.h>
#endif

#include "struct.h"
#include "execute.h"

void frame_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* ps,
	struct instruction** next)
{
	size_t i = 0;
	struct frame_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	{
		printf("line %4u: %8s %10s, %10zu", super->line,
			".frame", this->name, this->frame_size);
		
		vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			char vr[10];
			snprintf(vr, 10, "%%vr%u", u);
			printf(", %10s", vr);
		}));
	}
	#endif
	
	/* pushq %rbp:      */ *rs[1].as_pptr-- = rs[0].as_ptr;
	/* movq %rsp, %rbp: */  rs[0].as_ptr    = rs[1].as_ptr;
	/* subq fs, %rsp:   */  rs[1].as_int   -= this->frame_size;
	
	// copy parameters over:
	{
		i = 0, vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			rs[u] = ps[i++];
		}));
	}
	
	#ifdef ASM_VERBOSE
	{
		printf(" // (");
		
		printf("%%vr0 = %s, ", print_vreg(&rs[0]));
		
		printf("%%vr1 = %s", print_vreg(&rs[1]));
		
		vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			printf(", %%vr%u = %s", u, print_vreg(&rs[u]));
		}));
		
		printf(")\n");
	}
	#endif
	
	*next = super->next;
}


















