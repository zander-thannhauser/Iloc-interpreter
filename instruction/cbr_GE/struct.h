
#include "../struct.h"

struct cbr_GE_instruction
{
	struct instruction super;
	
	unsigned vr1, vr2;
	struct instruction* instruction;
};

