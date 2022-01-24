
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance loadAI_instruction_inheritance = {
	.execute = loadAI_instruction_execute,
	.free = free_loadAI_instruction,
};

