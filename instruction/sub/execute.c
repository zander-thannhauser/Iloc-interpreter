
#include <sys/param.h>

#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void sub_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	struct sub_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	char vr1[10];
	char vr2[10];
	char vr3[10];
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		snprintf(vr3, 10, "%%vr%u", this->vr3);
		
		printf("line %4i: %8s %10s, %10s => %10s  %10s", super->line,
			"sub", vr1, vr2, vr3, "");
	}
	#endif
	
	rs[this->vr3].as_int = rs[this->vr1].as_int - rs[this->vr2].as_int;
	
	#ifdef ASM_VERBOSE
	{
		rs[this->vr3].kind = MAX(rs[this->vr1].kind, rs[this->vr2].kind);
		
		printf(" // (%s = %s, ", vr1, print_vreg(&rs[this->vr1]));
		printf("%s = %s, ", vr2, print_vreg(&rs[this->vr2]));
		printf("%s = %s)\n", vr3, print_vreg(&rs[this->vr3]));
	}
	#endif
	
	stats->subs++;
	stats->total++;
	
	*next = super->next;
}
















