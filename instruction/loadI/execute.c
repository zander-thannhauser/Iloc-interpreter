
#include <stdio.h>
#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void loadI_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* registers,
	union vregister* parameters,
	struct instruction** next)
{
	char vr[10];
	struct loadI_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		snprintf(vr, 10, "%%vr%u", this->vr);
		
		printf("line %4i: %8s %10i  %10s => %-10s",
			super->line, "loadI", this->intlit, "", vr);
	}
	
	registers[this->vr].as_int = this->intlit;
	
	if (debug)
		printf(" // (%%vr%u = %i)\n", this->vr, registers[this->vr].as_int);
	
	*next = super->next;
	
	stats->total++;
}















