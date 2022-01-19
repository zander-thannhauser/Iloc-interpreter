
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance fmult_instruction_inheritance = {
	.execute = fmult_instruction_execute,
	.free = free_fmult_instruction,
};

