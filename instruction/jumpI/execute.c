
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void jumpI_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	union vregister* parameters,
	struct instruction** next)
{
	char vr[10];
	struct jumpI_instruction* const this = (typeof(this)) super;
	
	TODO;
	#if 0
	if (debug)
	{
		snprintf(vr, 10, "%%vr%u", this->vr);
		
		printf("line %4i: %8s %10s  %10s -> %-10p", super->line,
			"jumpI", vr, "", this->instruction);
	}
	
	int vr_value = rs[this->vr].as_int;
	
	*next = vr_value ? this->instruction : super->next;
	
	if (debug)
	{
		printf(" // (%s = %i, %s = %p)\n",
			vr, vr_value,
			"%rip", *next);
	}
	#endif
	
	stats->total++;
}

