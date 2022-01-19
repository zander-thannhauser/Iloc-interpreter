
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance f2i_instruction_inheritance = {
	.execute = f2i_instruction_execute,
	.free = free_f2i_instruction,
};

