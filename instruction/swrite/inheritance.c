
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance swrite_instruction_inheritance = {
	.execute = swrite_instruction_execute,
	.free = free_swrite_instruction,
};

