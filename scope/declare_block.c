
#include <assert.h>
#include <stdio.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <avl/avl.h>

#include <instruction/struct.h>

#include "block/new.h"
#include "unresolved/struct.h"

#include "struct.h"
#include "declare_block.h"

int scope_declare_block(
	struct scope* this,
	char* label,
	struct instruction* instruction)
{
	int error = 0;
	struct block* block = NULL;
	struct avl_node_t* node;
	ENTER;
	
	error = new_block(&block, label, instruction);
	
	if (!error && (node = avl_search(this->unresolved, &label)))
	{
		struct unresolved* u = node->item;
		u->instruction->next = tinc(instruction);
		avl_delete_node(this->unresolved, node);
	}
		
	if (!error && !avl_insert(this->blocks, block))
	{
		TODO;
		error = 1;
	}
	
	if (error)
		tfree(block);
	
	EXIT;
	return error;
}














