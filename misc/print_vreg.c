
#ifdef ASM_VERBOSE

#include <structs/vregister.h>

#include "print_vreg.h"

static char buffer[50];

char* print_vreg(struct vregister* this)
{
	switch (this->kind)
	{
		case vk_int: snprintf(buffer, 50, "%i",  this->as_int);   break;
		case vk_ptr: snprintf(buffer, 50, "%p",  this->as_ptr);   break;
		case vk_flt: snprintf(buffer, 50, "%gf", this->as_float); break;
	}
	
	return buffer;
}

#endif
