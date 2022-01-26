
#include "../struct.h"

struct storeAI_instruction
{
	struct instruction super;
	
	unsigned val;
	
	unsigned dst;
	
	int index;
};

