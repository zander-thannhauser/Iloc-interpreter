
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance testlt_instruction_inheritance = {
	.execute = testlt_instruction_execute,
	.free = free_testlt_instruction,
};

