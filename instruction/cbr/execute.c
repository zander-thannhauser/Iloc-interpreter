
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void cbr_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	struct cbr_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	char vr[10];
	{
		snprintf(vr, 10, "%%vr%u", this->vr);
		
		printf("line %4i: %8s %10s  %10s -> %-10p", super->line,
			"cbr", vr, "", this->instruction);
	}
	#endif
	
	int vr_value = rs[this->vr].as_int;
	
	*next = vr_value ? this->instruction : super->next;
	
	#ifdef ASM_VERBOSE
	{
		printf(" // (%s = %s, ", vr, print_vreg(&rs[this->vr]));
		printf("%s = %p)\n", "%rip", *next);
	}
	#endif
	
	stats->total++;
}




