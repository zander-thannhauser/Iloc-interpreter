
#include <debug.h>

#include <structs/vregister.h>

#include "struct.h"
#include "execute.h"

void comp_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	struct instruction** next)
{
	char vr1[10];
	char vr2[10];
	char vr3[10];
	struct comp_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		snprintf(vr3, 10, "%%vr%u", this->vr3);
		
		printf("line %4i: %8s %8s, %8s => %-16s", super->line,
			"comp", vr1, vr2, vr3);
	}
	
	int32_t vr1_value = rs[this->vr1].as_int;
	int32_t vr2_value = rs[this->vr2].as_int;
	int32_t vr3_value;
	
	if (vr1_value > vr2_value)
		vr3_value = +1;
	else if (vr1_value < vr2_value)
		vr3_value = -1;
	else
		vr3_value = 0;
	
	rs[this->vr3].as_int = vr3_value;
	
	if (debug)
	{
		printf(" // (%s = %i, %s = %i, %s = %i)\n",
			vr1, vr1_value,
			vr2, vr2_value,
			vr3, vr3_value);
	}
	
	*next = super->next;
}













