
#include "../struct.h"

struct fload_instruction
{
	struct instruction super;
	
	unsigned src;
	unsigned dst;
};

