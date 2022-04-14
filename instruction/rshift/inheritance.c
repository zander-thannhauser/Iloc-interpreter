
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance rshift_instruction_inheritance = {
	.execute = rshift_instruction_execute,
	.free = free_rshift_instruction,
};

