
#include "../struct.h"

struct call_instruction
{
	struct instruction super;
	
	struct instruction* callme;
	
	struct vregister_ll* args;
};

