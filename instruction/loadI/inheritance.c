
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance loadI_instruction_inheritance = {
	.execute = loadI_instruction_execute,
	.free = free_loadI_instruction,
};

