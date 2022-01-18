
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance load_instruction_inheritance = {
	.execute = load_instruction_execute,
	.free = free_load_instruction,
};

