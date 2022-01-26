
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

#include <defines/argv0.h>

#include <enums/error.h>

#include <memory/tmalloc.h>
#include <memory/tfree.h>

#include <avl/avl.h>

#include "block/compare.h"
#include "block/free.h"
#include "global/compare.h"
#include "global/free.h"

#include "struct.h"
#include "free.h"
#include "new.h"

int new_scope(struct scope** new)
{
	int error = 0;
	struct avl_tree_t* blocks = NULL;
	struct avl_tree_t* globals = NULL;
	struct avl_tree_t* unresolved = NULL;
	struct scope* this = NULL;
	ENTER;
	
	if (false
		|| !(blocks     = avl_alloc_tree(compare_blocks,     tfree))
		|| !(globals    = avl_alloc_tree(compare_globals,    tfree))
		|| !(unresolved = avl_alloc_tree(compare_blocks, tfree)))
	{
		fprintf(stderr, "%s: avl_alloc_tree: %m\n", argv0);
		error = e_out_of_memory;
	}
	else
		error = tmalloc((void**) &this, sizeof(*this), free_scope);
	
	if (!error)
	{
		this->blocks = blocks, blocks = NULL;
		this->globals = globals, globals = NULL;
		this->unresolved = unresolved, unresolved = NULL;
		
		*new = this;
	}
	
	avl_free_tree(blocks);
	avl_free_tree(globals);
	avl_free_tree(unresolved);
	
	EXIT;
	return error;
}
















