
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void iret_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	char vr[10];
	struct iret_instruction* const this = (typeof(this)) super;
	
	TODO;
	#if 0
	if (debug)
	{
		snprintf(vr, 10, "%%vr%u", this->vr);
		
		printf("line %4u: %8s %10s  %10s    %10s",
			super->line, "iret", vr, "", "");
	}
	
	int vr_backup = rs[this->vr].as_int;
	
	parameters[0].as_int = vr_backup;
	
	/* movq %rbp, %rsp: */  rs[1].as_ptr =    rs[0].as_ptr;
	/* pop %rbp:        */  rs[0].as_ptr = *++rs[1].as_pptr;
	/* jump (pop %rsp):*/  *next         = *++rs[1].as_pptr;
	
	if (debug)
		printf(" // (%%vr0 = %p, %%vr1 = %p, %s = %i)\n",
			rs[0].as_ptr, rs[1].as_ptr, vr, vr_backup);
	
	stats->total++;
	#endif
}












