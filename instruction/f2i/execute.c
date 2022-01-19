
#include <debug.h>

#include <structs/vregister.h>

#include "struct.h"
#include "execute.h"

void f2i_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* registers,
	struct instruction** next)
{
	TODO;
	#if 0
	char vr_src[10];
	char vr_dst[10];
	struct f2i_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		snprintf(vr_src, 10, "%%vr%u", this->vr_src);
		snprintf(vr_dst, 10, "%%vr%u", this->vr_dst);
		
		printf("line %4i: %8s %8s  %8s => %-16s", super->line,
			"f2i", vr_src, "", vr_dst);
	}
	
	registers[this->vr_dst].as_int = registers[this->vr_src].as_int;
	
	if (debug)
		printf(" // (%s = %i, %s = %i)\n",
			vr_src, registers[this->vr_src].as_int,
			vr_dst, registers[this->vr_dst].as_int);
	
	*next = super->next;
	#endif
}









