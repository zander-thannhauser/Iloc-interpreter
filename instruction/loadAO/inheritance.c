
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance loadAO_instruction_inheritance = {
	.execute = loadAO_instruction_execute,
	.free = free_loadAO_instruction,
};

