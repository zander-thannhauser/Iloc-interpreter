
#include "../struct.h"

struct storeAO_instruction
{
	struct instruction super;
	
	unsigned val;
	unsigned dst;
	unsigned off;
};

