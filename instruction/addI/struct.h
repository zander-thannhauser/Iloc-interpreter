
#include "../struct.h"

struct addI_instruction
{
	struct instruction super;
	unsigned vr1; int literal; unsigned vr3;
};

