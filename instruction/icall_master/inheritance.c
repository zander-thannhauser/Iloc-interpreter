
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance icall_master_instruction_inheritance = {
	.execute = icall_master_instruction_execute,
	.free = free_icall_master_instruction,
};

