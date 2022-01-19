
#include "struct.h"
#include "foreach.h"

void vregister_ll_foreach(
	struct vregister_ll* this,
	void (*callme)(unsigned))
{
	for (struct vregister_ll_link* i = this->head;
		i; i = i->next)
	{
		callme(i->element);
	}
}

