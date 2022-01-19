

#include "struct.h"
#include "free_link.h"
#include "append.h"

int vregister_ll_append(
	struct vregister_ll* this,
	unsigned element)
{
	int error = 0;
	ENTER;
	
	struct vregister_ll_link* link = NULL;
	
	error = tmalloc(
		(void**) &link, sizeof(*link),
		(void (*)(void*)) free_vregister_ll_link);
	
	if (!error)
	{
		// append to end of ll
		
		link->element = element;
		link->next = NULL;
		
		if (this->tail)
			this->tail->next = tinc(link);
		
		tfree(this->tail), this->tail = tinc(link);
		
		if (!this->head)
			this->head = tinc(link);
		
		this->n++;
	}
	
	tfree(link);
	
	EXIT;
	return error;
}




