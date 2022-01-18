
#include "../struct.h"

struct loadI_instruction
{
	struct instruction super;
	
	int32_t intlit;
	unsigned vr;
};

