
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance icall_slave_instruction_inheritance = {
	.execute = icall_slave_instruction_execute,
	.free = free_icall_slave_instruction,
};

