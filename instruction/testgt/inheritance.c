
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance testgt_instruction_inheritance = {
	.execute = testgt_instruction_execute,
	.free = free_testgt_instruction,
};

