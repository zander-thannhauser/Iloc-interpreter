
#include "../struct.h"

struct icall_master_instruction
{
	struct instruction super;
	
	struct instruction* callme;
	
	struct vregister_ll* args;
	
	unsigned vr;
};

