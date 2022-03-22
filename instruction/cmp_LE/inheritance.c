
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance cmp_LE_instruction_inheritance = {
	.execute = cmp_LE_instruction_execute,
	.free = free_cmp_LE_instruction,
};

