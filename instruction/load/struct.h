
#include "../struct.h"

struct load_instruction
{
	struct instruction super;
	
	unsigned src;
	unsigned val;
};

