
#include <avl/avl.h>

#include "struct.h"
#include "free.h"

void free_scope(void* ptr)
{
	struct scope* const this = ptr;
	ENTER;
	
	avl_free_tree(this->blocks);
	avl_free_tree(this->globals);
	avl_free_tree(this->unresolved);

	EXIT;
}

