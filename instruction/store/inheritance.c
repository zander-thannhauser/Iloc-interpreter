
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance store_instruction_inheritance = {
	.execute = store_instruction_execute,
	.free = free_store_instruction,
};

