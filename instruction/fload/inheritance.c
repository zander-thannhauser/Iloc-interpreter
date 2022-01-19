
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance fload_instruction_inheritance = {
	.execute = fload_instruction_execute,
	.free = free_fload_instruction,
};

