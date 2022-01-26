
#include "inheritance.h"
#include "struct.h"
#include "execute.h"

void execute_instruction(
	struct instruction* this,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	return (this->inheritance->execute)(this, ps, stack, stats, next);
}

