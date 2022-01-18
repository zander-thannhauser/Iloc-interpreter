
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance ret_instruction_inheritance = {
	.execute = ret_instruction_execute,
	.free = free_ret_instruction,
};

