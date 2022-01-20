
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void fload_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	char vr1[10];
	char vr2[10];
	struct fload_instruction* const this = (typeof(this)) super;
	
	TODO;
	#if 0
	if (debug)
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		
		printf("line %4i: %8s %10s  %10s => %-10s", super->line,
			"fload", vr1, "", vr2);
	}
	
	float* vr1_value = rs[this->vr1].as_fptr;
	float  vr2_value = *vr1_value;
	
	rs[this->vr2].as_float = vr2_value;
	
	if (debug)
		printf(" // (%s = %p, *%s = %gf, %s = %gf)\n",
			vr1,  vr1_value,
			vr1, *vr1_value,
			vr2,  vr2_value);
	#endif
	
	stats->loads++;
	stats->total++;
	
	*next = super->next;
}












