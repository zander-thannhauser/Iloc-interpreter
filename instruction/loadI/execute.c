
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void loadI_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	char vr[10];
	char lit[20];
	struct loadI_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	{
		snprintf(vr, 10, "%%vr%u", this->vr);
		
		if (this->isint)
			sprintf(lit, "%i", this->intlit);
		else
			sprintf(lit, "%p", (void*) this->intlit);
		
		printf("line %4i: %8s %10s  %10s => %-10s",
			super->line, "loadI", lit, "", vr);
	}
	#endif
	
	rs[this->vr].as_int = this->intlit;
	
	#ifdef ASM_VERBOSE
	{
		rs[this->vr].kind = this->isint ? vk_int : vk_ptr;
		
		printf(" // (%%vr%u = %s)\n", this->vr, print_vreg(&rs[this->vr]));
	}
	#endif
	
	*next = super->next;
	
	stats->total++;
}















