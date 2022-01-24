
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance multI_instruction_inheritance = {
	.execute = multI_instruction_execute,
	.free = free_multI_instruction,
};

