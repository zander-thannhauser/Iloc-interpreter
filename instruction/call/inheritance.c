
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance call_instruction_inheritance = {
	.execute = call_instruction_execute,
	.free = free_call_instruction,
};

