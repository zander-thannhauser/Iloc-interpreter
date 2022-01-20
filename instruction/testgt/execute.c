
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void testgt_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	char vr1[10];
	char vr2[10];
	struct testgt_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		
		printf("line %4i: %8s %10s  %10s => %-10s", super->line,
			"testgt", vr1, "", vr2);
	}
	#endif
	
	rs[this->vr2].as_int = rs[this->vr1].as_int > 0;
	
	#ifdef ASM_VERBOSE
	{
		printf(" // (%s = %s, ", vr1, print_vreg(&rs[this->vr1]));
		printf("%s = %s)\n", vr2, print_vreg(&rs[this->vr2]));
	}
	#endif
	
	*next = super->next;
	
	stats->comparisons++;
	stats->total++;
}











