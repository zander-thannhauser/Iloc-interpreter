
#include "../struct.h"

struct cbr_instruction
{
	struct instruction super;
	
	unsigned vr;
	
	struct block* label;
};

