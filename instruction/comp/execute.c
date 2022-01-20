
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void comp_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	char vr1[10];
	char vr2[10];
	char vr3[10];
	struct comp_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		snprintf(vr3, 10, "%%vr%u", this->vr3);
		
		printf("line %4i: %8s %10s, %10s => %-10s", super->line,
			"comp", vr1, vr2, vr3);
	}
	#endif
	
	int vr1_value = rs[this->vr1].as_int;
	int vr2_value = rs[this->vr2].as_int;
	int vr3_value;
	
	if (vr1_value > vr2_value)
		vr3_value = +1;
	else if (vr1_value < vr2_value)
		vr3_value = -1;
	else
		vr3_value = 0;
	
	rs[this->vr3].as_int = vr3_value;
	
	#ifdef ASM_VERBOSE
	{
		rs[this->vr3].kind = vk_int;
		
		printf(" // (%s = %s, ", vr1, print_vreg(&rs[this->vr1]));
		printf("%s = %s, ", vr2, print_vreg(&rs[this->vr2]));
		printf("%s = %s)\n", vr3, print_vreg(&rs[this->vr3]));
	}
	#endif
	
	*next = super->next;
	
	stats->comparisons++;
	stats->total++;
}













