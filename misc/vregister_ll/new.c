

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_vregister_ll(
	struct vregister_ll** new)
{
	int error = 0;
	ENTER;
	
	struct vregister_ll* this = NULL;
	
	error = tmalloc(
		(void**) &this, sizeof(*this),
		(void (*)(void*)) free_vregister_ll);
	
	if (!error)
	{
		this->head = this->tail = NULL;
		this->n = 0;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

