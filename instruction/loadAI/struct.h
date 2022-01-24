
#include "../struct.h"

struct loadAI_instruction
{
	struct instruction super;
	
	unsigned vr1;
	int intlit;
	unsigned vr3;
};

