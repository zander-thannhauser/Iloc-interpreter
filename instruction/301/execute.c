
#include <debug.h>

#include "../struct.h"

#include "execute.h"

void _301_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* registers,
	struct instruction** next)
{
	*next = super->next;
}

