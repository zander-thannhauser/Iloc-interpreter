
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance iwrite_instruction_inheritance = {
	.execute = iwrite_instruction_execute,
	.free = free_iwrite_instruction,
};

