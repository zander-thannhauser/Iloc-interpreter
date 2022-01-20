
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void iwrite_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	char vr1[10];
	struct iwrite_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		
		printf("line %4i: %8s %10s  %10s    %-10s\n", super->line,
			"iwrite", vr1, "", "");
	}
	#endif
	
	int vr_value = rs[this->vr1].as_int;
	
	printf("%i\n", vr_value);
	
	*next = super->next;
	
	stats->total++;
}

