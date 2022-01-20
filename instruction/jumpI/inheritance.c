
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance jumpI_instruction_inheritance = {
	.execute = jumpI_instruction_execute,
	.free = free_jumpI_instruction,
};

