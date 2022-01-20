
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void ret_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	union vregister* parameters,
	struct instruction** next)
{
	struct ret_instruction* const this = (typeof(this)) super;
	
	if (debug)
		printf("line %4u: %8s %10s  %10s    %10s",
			super->line, "ret", "", "", "");
	
	/* movq %rbp, %rsp: */  rs[1].as_ptr =    rs[0].as_ptr;
	/* pop %rbp:        */  rs[0].as_ptr = *++rs[1].as_pptr;
	/* jump (pop %rsp):*/  *next         = *++rs[1].as_pptr;
	
	if (debug)
	{
		printf(" // (%%vr0 = %p, %%vr1 = %p)\n",
			rs[0].as_ptr, rs[1].as_ptr);
	}
	
	stats->total++;
	
}












