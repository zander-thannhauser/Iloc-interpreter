
#include "../struct.h"

struct cbr_EQ_instruction
{
	struct instruction super;
	
	unsigned vr1, vr2;
	
	struct block* label;
};

