
#include <stddef.h>

#include "../struct.h"

struct vregister_ll;

struct frame_instruction
{
	struct instruction super;
	
	char* name;
	size_t frame_size;
	
	struct vregister_ll* args;
};

