
#include <stdio.h>

#include <structs/stats.h>

#include "../struct.h"

#include "execute.h"

void nop_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	#ifdef ASM_VERBOSE
	printf("line %4i: %8s\n", super->line, "nop");
	#endif
	
	*next = super->next;
	
	stats->total++;
}

