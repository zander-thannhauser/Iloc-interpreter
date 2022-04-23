
#include "../struct.h"

struct rshiftI_instruction
{
	struct instruction super;
	unsigned vr1;
	signed literal;
	signed vr3;
};

