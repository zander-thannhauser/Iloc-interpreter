
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance mult_instruction_inheritance = {
	.execute = mult_instruction_execute,
	.free = free_mult_instruction,
};

