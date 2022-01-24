
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance addI_instruction_inheritance = {
	.execute = addI_instruction_execute,
	.free = free_addI_instruction,
};

