
#include "../struct.h"

struct cbrne_instruction
{
	struct instruction super;
	
	unsigned vr;
	
	struct block* label;
};

