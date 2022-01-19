
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_frame_instruction(struct instruction* super)
{
	struct frame_instruction* const this = (typeof(this)) super;
	ENTER;
	
	tfree(this->name);
	tfree(this->args);
	
	EXIT;
}
