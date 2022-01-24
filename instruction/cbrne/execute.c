
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void cbrne_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	struct cbrne_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	char vr[10];
	{
		snprintf(vr, 10, "%%vr%u", this->vr);
		
		printf("line %4i: %8s %10s  %10s -> %10p  %10s", super->line,
			"cbrne", vr, "", this->instruction, "");
	}
	#endif
	
	int vr_value = rs[this->vr].as_int;
	
	*next = !vr_value ? this->instruction : super->next;
	
	#ifdef ASM_VERBOSE
	{
		printf(" // (%s = %s, %s = %p)\n",
			vr, print_vreg(&rs[this->vr]),
			"%rip", *next);
	}
	#endif
	
	stats->total++;
}










