
#include <debug.h>

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
	struct instruction** next)
{
	size_t i = 0, n = 0;
	struct frame_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		printf("line %4u: %8s %s, %zu", super->line,
			".frame", this->name, this->frame_size);
		
		vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			printf(", %%vr%u", u);
			n++;
		}));
	}
	
	/* pushq %rbp:*/
	{
		int64_t* rsp = (int64_t*)(int64_t) rs[1].as_int;
		*rsp = rs[0].as_int;
		rs[1].as_int++;
	}
	
	/* movq %rsp, %rbp: */
	{
		rs[0].as_int = rs[1].as_int;
	}
	
	/* subq fs, %rsp: */
	{
		rs[1].as_int -= this->frame_size;
	}
	
	// copy parameters over:
	{
		union vregister tmp[n];
		
		for (i = 0; i < n; i++)
			tmp[i] = rs[i + 4];
		
		i = 0, vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			rs[u] = tmp[i++];
		}));
	}
	
	if (debug)
	{
		printf(" // (%%vr0 = 0x%X, %%vr1 = 0x%X",
			rs[0].as_int, rs[1].as_int);
		
		vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			printf(", %%vr%u = %i", u, rs[u].as_int);
		}));
		
		printf(")\n");
	}
	
	*next = super->next;
}


















