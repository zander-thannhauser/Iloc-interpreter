
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance storeAI_instruction_inheritance = {
	.execute = storeAI_instruction_execute,
	.free = free_storeAI_instruction,
};

