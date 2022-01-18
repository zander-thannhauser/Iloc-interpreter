
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance comp_instruction_inheritance = {
	.execute = comp_instruction_execute,
	.free = free_comp_instruction,
};

