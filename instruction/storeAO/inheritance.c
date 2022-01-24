
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance storeAO_instruction_inheritance = {
	.execute = storeAO_instruction_execute,
	.free = free_storeAO_instruction,
};

