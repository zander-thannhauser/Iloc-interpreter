
#include <stdio.h>

#include <avl/avl.h>

#include <defines/argv0.h>

#include <enums/error.h>

#include "unresolved/struct.h"

#include "struct.h"
#include "check_unresolved.h"

int scope_check_unresolved(struct scope* this)
{
	int error = 0;
	struct avl_node_t* node;
	ENTER;
	
	for (node = this->unresolved->head; node; node = node->next)
	{
		struct unresolved* u = node->item;
		
		fprintf(stderr, "%s: unresolved reference to '%s'!\n", argv0, u->name);
		
		error = e_unresolved_references;
	}
	
	EXIT;
	return error;
}

