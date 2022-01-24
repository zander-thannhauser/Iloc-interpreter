
#include <assert.h>
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
	struct iret_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	char vr[10];
	{
		snprintf(vr, 10, "%%vr%u", this->vr);
		
		printf("line %4u: %8s %10s  %10s    %10s",
			super->line, "iret", vr, "", "");
	}
	#endif
	
	int vr_backup = rs[this->vr].as_int;
	
	parameters[0].as_int = vr_backup;
	
	/* movq %rbp, %rsp: */  rs[1].as_ptr =    rs[0].as_ptr;
	/* pop %rbp:        */  rs[0].as_ptr = *++rs[1].as_pptr;
	/* jump (pop %rsp):*/  *next         = *++rs[1].as_pptr;
	
	#ifdef ASM_VERBOSE
	{
		printf(" // (%%vr0 = %p, %%vr1 = %p, %s = %i)\n",
			rs[0].as_ptr, rs[1].as_ptr, vr, vr_backup);
	}
	#endif
	
	stats->total++;
}












