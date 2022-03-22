
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance cmp_LT_instruction_inheritance = {
	.execute = cmp_LT_instruction_execute,
	.free = free_cmp_LT_instruction,
};

