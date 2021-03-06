
#include <memory/tfree.h>

#include "inheritance.h"
#include "struct.h"
#include "free.h"

void free_instruction(void* ptr)
{
	ENTER;
	
	struct instruction* const this = ptr;
	
	(this->inheritance->free)(this);
	
	tfree(this->next);
	
	EXIT;
}
