
#include <debug.h>

#include "../struct.h"

#include "execute.h"

void nop_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* registers,
	struct instruction** next)
{
	if (debug)
		printf("line %4i: %8s\n", super->line, "nop");
	
	*next = super->next;
}

