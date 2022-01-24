
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance cbr_LE_instruction_inheritance = {
	.execute = cbr_LE_instruction_execute,
	.free = free_cbr_LE_instruction,
};

