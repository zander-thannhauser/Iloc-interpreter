
#include "../struct.h"

struct cbr_GT_instruction
{
	struct instruction super;
	
	unsigned vr1, vr2;
	
	struct block* label;
};

