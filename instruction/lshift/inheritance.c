
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance lshift_instruction_inheritance = {
	.execute = lshift_instruction_execute,
	.free = free_lshift_instruction,
};

