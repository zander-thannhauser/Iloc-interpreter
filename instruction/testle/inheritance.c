
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance testle_instruction_inheritance = {
	.execute = testle_instruction_execute,
	.free = free_testle_instruction,
};

