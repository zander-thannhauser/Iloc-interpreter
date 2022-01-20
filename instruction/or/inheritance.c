
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance or_instruction_inheritance = {
	.execute = or_instruction_execute,
	.free = free_or_instruction,
};

