
#include <assert.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void cmp_NE_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	TODO;
	#if 0
	struct cmp_NE_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	char vr1[10];
	char vr2[10];
	char vr3[10];
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		snprintf(vr3, 10, "%%vr%u", this->vr3);
		
		printf("line %4i: %8s %10s, %10s => %10s  %10s", super->line,
			"cmp_NE", vr1, vr2, vr3, "");
	}
	#endif
	
	int vr1_value = rs[this->vr1].as_int;
	int vr2_value = rs[this->vr2].as_int;
	int vr3_value = vr1_value != vr2_value;
	
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
	#endif
	
	stats->comparisons++;
	stats->total++;
}













