
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance cbr_NE_instruction_inheritance = {
	.execute = cbr_NE_instruction_execute,
	.free = free_cbr_NE_instruction,
};

