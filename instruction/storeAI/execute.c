
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void storeAI_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	struct storeAI_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	char vr1[10];
	char vr2[10];
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		
		printf("line %4i: %8s %10s  %10s => %10s, %10i", super->line,
			"storeAI", vr1, "", vr2, this->index);
	}
	#endif
	
	int  vr1_value = rs[this->vr1].as_int;
	int* vr2_value = rs[this->vr2].as_ptr + this->index;
	
	*vr2_value = vr1_value;
	
	#ifdef ASM_VERBOSE
	{
		rs[this->vr2].kind = vk_ptr;
		
		printf(" // (%s = %i, %s + %i = %p, *(%s + %i) = %i)\n",
			vr1,               vr1_value,
			vr2, this->index,  vr2_value,
			vr2, this->index, *vr2_value);
	}
	#endif
	
	stats->stores++;
	stats->total++;
	
	*next = super->next;
}

















