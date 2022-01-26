
#include <structs/vregister.h>

#include "../struct.h"

struct loadI_instruction
{
	struct instruction super;
	
	struct vregister literal;
	
	unsigned vr;
};

