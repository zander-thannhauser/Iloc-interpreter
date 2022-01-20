
#include "../struct.h"

#include "execute.h"

void _301_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* registers,
	struct vregister* parameters,
	struct instruction** next)
{
	*next = super->next;
}

