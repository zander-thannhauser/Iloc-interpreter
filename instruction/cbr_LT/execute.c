
#include <stdio.h>
#include <stdbool.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void cbr_LT_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	struct cbr_LT_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	char vr1[10];
	char vr2[10];
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		
		printf("line %4i: %8s %10s, %10s -> %10p  %10s", super->line,
			"cbr_LT", vr1, vr2, this->instruction, "");
	}
	#endif
	
	int vr1_value = rs[this->vr1].as_int;
	int vr2_value = rs[this->vr2].as_int;
	
	bool conditional = vr1_value < vr2_value;
	
	*next = conditional ? this->instruction : super->next;
	
	#ifdef ASM_VERBOSE
	{
		printf(" // (%s < %s = %s, ", vr1, vr2, conditional ? "true" : "false");
		printf("%s = %p)\n", "%rip", *next);
	}
	#endif
	
	stats->total++;
}




