
#include <debug.h>

#include <structs/vregister.h>

#include "struct.h"
#include "execute.h"

void cbrne_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	struct instruction** next)
{
	char vr[10];
	struct cbrne_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		snprintf(vr, 10, "%%vr%u", this->vr);
		
		printf("line %4i: %8s %8s  %8s -> %-16p", super->line,
			"cbrne", vr, "", this->instruction);
	}
	
	int32_t vr_value = rs[this->vr].as_int;
	
	*next = !vr_value ? this->instruction : super->next;
	
	if (debug)
	{
		printf(" // (%s = %i, %s = %p)\n",
			vr, vr_value,
			"%rip", *next);
	}
}

