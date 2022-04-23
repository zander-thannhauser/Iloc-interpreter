
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance rshiftI_instruction_inheritance = {
	.execute = rshiftI_instruction_execute,
	.free = free_rshiftI_instruction,
};

