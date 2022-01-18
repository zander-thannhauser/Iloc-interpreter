
#include "../inheritance.h"

#include "inheritance.h"
#include "execute.h"
#include "free.h"

const struct instruction_inheritance frame_instruction_inheritance = {
	.execute = frame_instruction_execute,
	.free = free_frame_instruction,
};

