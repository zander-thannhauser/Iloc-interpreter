
#include "../struct.h"

struct jumpI_instruction
{
	struct instruction super;
	
	struct block* label;
};

