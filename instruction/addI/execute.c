
#include <sys/param.h>

#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void addI_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	struct addI_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	char vr1[10];
	char vr3[10];
	
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr3, 10, "%%vr%u", this->vr3);
		
		printf("line %4i: %8s %10s, %10i => %10s  %10s", super->line,
			"addI", vr1, this->literal, vr3, "");
	}
	#endif
	
	int vr1_backup = rs[this->vr1].as_int;
	
	#ifdef ASM_VERBOSE
	{
		printf(" // (");
		printf("%s = %s, ", vr1, print_vreg(&rs[this->vr1]));
		
		rs[this->vr3].kind = rs[this->vr1].kind;
		rs[this->vr3].as_int = vr1_backup + this->literal;
		printf("%s = %s)\n", vr3, print_vreg(&rs[this->vr3]));
	}
	#else
	rs[this->vr3].as_int = vr1_backup + this->literal;
	#endif
	
	stats->adds++;
	stats->total++;
	
	*next = super->next;
}











