
#include "../struct.h"

struct loadI_instruction
{
	struct instruction super;
	
	int intlit;
	bool isint;
	unsigned vr;
};

