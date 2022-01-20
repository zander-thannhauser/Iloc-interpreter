
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance testge_instruction_inheritance = {
	.execute = testge_instruction_execute,
	.free = free_testge_instruction,
};

