
#include <debug.h>

#include <structs/vregister.h>

#include "struct.h"
#include "execute.h"

void testle_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	struct instruction** next)
{
	char vr1[10];
	char vr2[10];
	struct testle_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		
		printf("line %4i: %8s %8s  %8s => %-16s", super->line,
			"testle", vr1, "", vr2);
	}
	
	int32_t vr1_value = rs[this->vr1].as_int;
	int32_t vr2_value = vr1_value <= 0;
	
	rs[this->vr2].as_int = vr2_value;
	
	if (debug)
	{
		printf(" // (%s = %i, %s = %i)\n",
			vr1, vr1_value,
			vr2, vr2_value);
	}
	
	*next = super->next;
}

