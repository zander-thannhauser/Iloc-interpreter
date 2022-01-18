
#include <debug.h>

#include <avl/avl.h>

#include "global/new.h"
#include "global/free.h"

#include "struct.h"
#include "declare_global.h"

int scope_declare_global(
	struct scope* this,
	char* label,
	size_t size,
	void* data)
{
	int error = 0;
	struct global* global = NULL;
	ENTER;
	
	dpvs(label);
	dpv(size);
	dpvsn(data, size);
	
	error = new_global(&global, label, size, data);
	
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


















