
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance fadd_instruction_inheritance = {
	.execute = fadd_instruction_execute,
	.free = free_fadd_instruction,
};

