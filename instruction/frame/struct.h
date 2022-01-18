
#include "../struct.h"

struct frame_instruction
{
	struct instruction super;
	char* name;
	size_t frame_size;
};

