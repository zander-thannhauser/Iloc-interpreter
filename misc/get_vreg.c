
#include <structs/stack.h>

#include "get_vreg.h"

struct vregister* get_vreg(struct stack* stack, unsigned index)
{
	switch (index) {
		case  0: return &stack->rbp;
		case  1: return &stack->rsp;
		default: return &stack->rbp.as_rptr[index];
	}
}

