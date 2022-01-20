
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void store_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	char vr1[10];
	char vr2[10];
	struct store_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		
		printf("line %4i: %8s %10s  %10s => %-10s", super->line,
			"store", vr1, "", vr2);
	}
	#endif
	
	int  vr1_value = rs[this->vr1].as_int;
	int* vr2_value = rs[this->vr2].as_iptr;
	
	*vr2_value = vr1_value;
	
	#ifdef ASM_VERBOSE
	{
		rs[this->vr2].kind = vk_ptr;
		
		printf(" // (%s = %i, %s = %p, *%s = %i)\n",
			vr1,  vr1_value,
			vr2,  vr2_value,
			vr2, *vr2_value);
	}
	#endif
	
	stats->stores++;
	stats->total++;
	
	*next = super->next;
}

















