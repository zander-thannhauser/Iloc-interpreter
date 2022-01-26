
#include "../struct.h"

struct cbr_LT_instruction
{
	struct instruction super;
	
	unsigned vr1, vr2;
	
	struct block* label;
};

