
#include <assert.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void fadd_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	struct fadd_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	char vr1[10];
	char vr2[10];
	char vr3[10];
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		snprintf(vr3, 10, "%%vr%u", this->vr3);
		
		printf("line %4i: %8s %10s, %10s => %-10s", super->line,
			"fadd", vr1, vr2, vr3);
	}
	#endif
	
	float vr1_backup = rs[this->vr1].as_float;
	float vr2_backup = rs[this->vr2].as_float;
	float vr3_backup = vr1_backup + vr2_backup;
	
	rs[this->vr3].as_float = vr3_backup;
	
	#ifdef ASM_VERBOSE
	{
		printf(" // (%s = %gf, %s = %gf, %s = %gf)\n",
			vr1, vr1_backup,
			vr2, vr2_backup,
			vr3, vr3_backup);
	}
	#endif
	
	*next = super->next;
	
	stats->total++;
}











