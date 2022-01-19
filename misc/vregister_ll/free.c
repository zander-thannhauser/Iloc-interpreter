
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_vregister_ll(
	struct vregister_ll* this)
{
	tfree(this->head);
	tfree(this->tail);
}

