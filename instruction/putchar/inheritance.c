
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance putchar_instruction_inheritance = {
	.execute = putchar_instruction_execute,
	.free = free_putchar_instruction,
};

