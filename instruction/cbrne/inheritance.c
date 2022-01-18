
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance cbrne_instruction_inheritance = {
	.execute = cbrne_instruction_execute,
	.free = free_cbrne_instruction,
};

