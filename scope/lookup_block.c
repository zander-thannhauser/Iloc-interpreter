
#include <avl/avl.h>

#include <debug.h>

#include <instruction/301/new.h>

#include "block/struct.h"

#include "unresolved/struct.h"
#include "unresolved/new.h"

#include "struct.h"
#include "lookup_block.h"

int scope_lookup_block(
	struct scope* this,
	char* label,
	struct instruction** out)
{
	int error = 0;
	struct avl_node_t* node;
	ENTER;
	
	if ((node = avl_search(this->blocks, &label)))
	{
		struct block* b = node->item;
		*out = tinc(b->instruction);
	}
	else if ((node = avl_search(this->unresolved, &label)))
	{
		struct unresolved* b = node->item;
		dpvs(b->name);
		TODO;
	}
	else
	{
		char* label_copy = NULL;
		struct instruction* redirect = NULL;
		struct unresolved* unresolved = NULL;
		
		error = 0
			?: tstrdup(&label_copy, label)
			?: new_301_instruction(&redirect)
			?: new_unresolved(&unresolved, label_copy, redirect);
		
		if (!error)
		{
			if (avl_insert(this->unresolved, unresolved))
			{
				tinc(unresolved);
			}
			else
			{
				TODO;
				error = 1;
			}
		}
		
		if (!error)
			*out = tinc(redirect);
		
		tfree(unresolved);
		tfree(label_copy);
		tfree(redirect);
	}
	
	EXIT;
	return error;
}













