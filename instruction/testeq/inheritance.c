
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance testeq_instruction_inheritance = {
	.execute = testeq_instruction_execute,
	.free = free_testeq_instruction,
};

