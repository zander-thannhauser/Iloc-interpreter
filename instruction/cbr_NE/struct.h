
#include "../struct.h"

struct cbr_NE_instruction
{
	struct instruction super;
	
	unsigned vr1, vr2;
	
	struct block* label;
};

