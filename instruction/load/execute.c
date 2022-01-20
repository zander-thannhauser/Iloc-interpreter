
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void load_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	char vr1[10];
	char vr2[10];
	struct load_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		
		printf("line %4i: %8s %10s  %10s => %-10s", super->line,
			"load", vr1, "", vr2);
	}
	#endif
	
	int* vr1_value = rs[this->vr1].as_iptr;
	int  vr2_value = *rs[this->vr1].as_iptr;
	
	rs[this->vr2].as_int = vr2_value;
	
	#ifdef ASM_VERBOSE
	{
		printf(" // (%s = %p, *%s = %i, %s = %i)\n",
			vr1,  vr1_value,
			vr1, *vr1_value,
			vr2,  vr2_value);
	}
	#endif
	
	stats->loads++;
	stats->total++;
	
	*next = super->next;
}












