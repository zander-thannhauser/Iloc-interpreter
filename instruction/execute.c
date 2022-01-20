
#include "inheritance.h"
#include "struct.h"
#include "execute.h"

void execute_instruction(
	struct instruction* this,
	struct stats* stats,
	struct vregister* registers,
	struct vregister* params,
	struct instruction** next)
{
	return (this->inheritance->execute)(this, stats, registers, params, next);
}

