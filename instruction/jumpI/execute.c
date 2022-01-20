
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
	struct jumpI_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		printf("line %4i: %8s %10s  %10s -> %-10p\n", super->line,
			"jumpI", "", "", this->instruction);
	}
	
	*next = this->instruction;
	
	stats->total++;
}

