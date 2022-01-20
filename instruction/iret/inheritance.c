
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance iret_instruction_inheritance = {
	.execute = iret_instruction_execute,
	.free = free_iret_instruction,
};

