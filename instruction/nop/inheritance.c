
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance nop_instruction_inheritance = {
	.execute = nop_instruction_execute,
	.free = free_nop_instruction,
};

