
#include <debug.h>

#include <avl/avl.h>

#include "global/new.h"
#include "global/free.h"

#include "struct.h"
#include "declare_global.h"

int scope_declare_global(
	struct scope* this,
	char* label,
	void* data)
{
	int error = 0;
	struct global* global = NULL;
	ENTER;
	
	dpvs(label);
	dpv(data);
	dpv(this->globals);
	
	error = new_global(&global, label, data);
	
	dpv(global);
	
	if (error);
	else if (avl_insert(this->globals, global))
	{
		tinc(global);
	}
	else
	{
		TODO;
		error = e_out_of_memory;
	}
	
	tfree(global);
	
	EXIT;
	return error;
}


















