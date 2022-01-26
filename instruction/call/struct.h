
#include "../struct.h"

struct call_instruction
{
	struct instruction super;
	
	struct block* callme;
	
	struct vregister_ll* args;
};

