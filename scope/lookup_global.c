
#include <avl/avl.h>

#include "global/struct.h"

#include "struct.h"
#include "lookup_global.h"

int scope_lookup_global(
	struct scope* this,
	char* label,
	int32_t* out)
{
	int error = 0;
	struct avl_node_t* node;
	ENTER;
	
	if ((node = avl_search(this->globals, &label)))
	{
		struct global* g = node->item;
		
		dpv(g->value);
		
		*out = (int32_t) (int64_t) g->value;
	}
	else
	{
		TODO;
	}
	
	EXIT;
	return error;
}












