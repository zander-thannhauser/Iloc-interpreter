
#include "../struct.h"

struct loadI_instruction
{
	struct instruction super;
	
	int intlit;
	unsigned vr;
};

