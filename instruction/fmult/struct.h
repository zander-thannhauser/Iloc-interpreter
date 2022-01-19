
#include "../struct.h"

struct fmult_instruction
{
	struct instruction super;
	
	unsigned vr1;
	unsigned vr2;
	unsigned vr3;
};

