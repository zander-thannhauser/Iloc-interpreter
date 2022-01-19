
#include <memory/tfree.h>

#include "struct.h"
#include "free_link.h"

void free_vregister_ll_link(
	struct vregister_ll_link* this)
{
	tfree(this->next);
}

