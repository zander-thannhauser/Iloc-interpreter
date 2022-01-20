
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance testne_instruction_inheritance = {
	.execute = testne_instruction_execute,
	.free = free_testne_instruction,
};

