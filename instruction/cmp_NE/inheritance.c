
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance cmp_NE_instruction_inheritance = {
	.execute = cmp_NE_instruction_execute,
	.free = free_cmp_NE_instruction,
};

