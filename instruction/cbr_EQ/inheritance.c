
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance cbr_EQ_instruction_inheritance = {
	.execute = cbr_EQ_instruction_execute,
	.free = free_cbr_EQ_instruction,
};

