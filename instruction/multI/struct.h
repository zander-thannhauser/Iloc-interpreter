
#include "../struct.h"

struct multI_instruction
{
	struct instruction super;
	unsigned vr1;
	signed literal;
	signed vr3;
};

