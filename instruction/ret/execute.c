
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void ret_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	struct ret_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	{
		printf("line %4u: %8s %10s  %10s    %10s  %10s",
			super->line, "ret", "", "", "", "");
	}
	#endif
	
	/* movq %rbp, %rsp: */  rs[1].as_ptr =    rs[0].as_ptr;
	/* pop %rbp:        */  rs[0].as_ptr = *++rs[1].as_pptr;
	/* jump (pop %rsp):*/  *next         = *++rs[1].as_pptr;
	
	#ifdef ASM_VERBOSE
	{
		printf(" // (%%vr0 = %p, %%vr1 = %p)\n",
			rs[0].as_ptr, rs[1].as_ptr);
	}
	#endif
	
	stats->total++;
	
}












