
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance iread_instruction_inheritance = {
	.execute = iread_instruction_execute,
	.free = free_iread_instruction,
};

