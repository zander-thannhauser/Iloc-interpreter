
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance fwrite_instruction_inheritance = {
	.execute = fwrite_instruction_execute,
	.free = free_fwrite_instruction,
};

