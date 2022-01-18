
#include "../struct.h"

struct load_instruction
{
	struct instruction super;
	
	unsigned vr1;
	unsigned vr2;
	unsigned vr3;
};

