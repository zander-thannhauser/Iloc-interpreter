
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance _301_instruction_inheritance = {
	.execute = _301_instruction_execute,
	.free = free_301_instruction,
};

