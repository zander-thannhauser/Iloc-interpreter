
#include <assert.h>
#include <stddef.h>

#include <avl/avl.h>

#include <memory/tinc.h>
#include <memory/tstrdup.h>
#include <memory/tfree.h>

#include "block/new.h"

#include "struct.h"
#include "lookup_block.h"

int scope_lookup_block(
	struct scope* this,
	char* label,
	struct block** out)
{
	int error = 0;
	struct avl_node_t* node;
	ENTER;
	
	if ((node = avl_search(this->blocks, &label)))
	{
		struct block* b = node->item;
		
		*out = tinc(b);
	}
	else if ((node = avl_search(this->unresolved, &label)))
	{
		struct block* b = node->item;
		
		*out = tinc(b);
	}
	else
	{
		char* label_copy = NULL;
		struct block* unresolved = NULL;
		
		error = 0
			?: tstrdup(&label_copy, label)
			?: new_block(&unresolved, label_copy, NULL);
		
		if (!error && !avl_insert(this->unresolved, unresolved))
		{
			TODO;
			error = 1;
		}
		
		if (error)
			tfree(unresolved);
		else
			*out = tinc(unresolved);
		
		tfree(label_copy);
	}
	
	EXIT;
	return error;
}













