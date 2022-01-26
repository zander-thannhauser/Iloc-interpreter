
#ifdef ASM_VERBOSE

#include <stdio.h>

#include <macros/N.h>

#include <structs/vregister.h>

#include "print_vreg.h"

char* print_vreg(char buffer[20], struct vregister* this)
{
	switch (this->kind)
	{
		case vk_unset: NOPE;
		case vk_bol: strcpy(buffer, this->as_int ? "true" : "false"); break;
		case vk_cmp:
			if (this->as_int < 0)
				strcpy(buffer, "<");
			else if (this->as_int > 0)
				strcpy(buffer, ">");
			else
				strcpy(buffer, "=");
			break;
		case vk_int: snprintf(buffer, 20, "%i",  this->as_int);   break;
		case vk_ptr: snprintf(buffer, 20, "%p",  this->as_ptr);   break;
		case vk_flt: snprintf(buffer, 20, "%gf", this->as_float); break;
	}
	
	return buffer;
}

#endif
