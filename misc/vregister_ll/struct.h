
#include <stddef.h>

struct vregister_ll_link
{
	unsigned element;
	struct vregister_ll_link* next;
};

struct vregister_ll
{
	struct vregister_ll_link* head, *tail;
	size_t n;
};

