
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance i2i_instruction_inheritance = {
	.execute = i2i_instruction_execute,
	.free = free_i2i_instruction,
};

