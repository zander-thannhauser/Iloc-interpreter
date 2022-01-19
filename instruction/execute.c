
#include "inheritance.h"
#include "struct.h"
#include "execute.h"

void execute_instruction(
	struct instruction* this,
	bool debug,
	struct stats* stats,
	union vregister* registers,
	union vregister* params,
	struct instruction** next)
{
	return (this->inheritance->execute)(this, debug, stats, registers, params, next);
}

