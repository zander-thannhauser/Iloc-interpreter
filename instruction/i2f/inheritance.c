
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance i2f_instruction_inheritance = {
	.execute = i2f_instruction_execute,
	.free = free_i2f_instruction,
};

