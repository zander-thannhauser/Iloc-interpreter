
#include <assert.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <scope/block/struct.h>

#include "struct.h"
#include "execute.h"

void jumpI_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct jumpI_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	{
		printf("line %4i: %8s %10s  %10s -> %10p  %10s\n", super->line,
			"jumpI", "", "", this->label->name, "");
	}
	#endif
	
	*next = this->label->instruction;
	
	stats->total++;
	
}

