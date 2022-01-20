
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance mod_instruction_inheritance = {
	.execute = mod_instruction_execute,
	.free = free_mod_instruction,
};

