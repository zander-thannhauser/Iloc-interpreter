
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance add_instruction_inheritance = {
	.execute = add_instruction_execute,
	.free = free_add_instruction,
};

