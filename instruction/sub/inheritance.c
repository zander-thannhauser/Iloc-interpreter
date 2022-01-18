
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance sub_instruction_inheritance = {
	.execute = sub_instruction_execute,
	.free = free_sub_instruction,
};

