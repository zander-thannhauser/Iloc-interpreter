#include <assert.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>

#include "struct.h"
#include "execute.h"

void iwrite_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct iwrite_instruction* const this = (typeof(this)) super;
	
	struct vregister* vr = get_vreg(stack, this->vr1);
	
	#ifdef ASM_VERBOSE
	char name[10];
	{
		snprintf(name, 10, "%%vr%u", this->vr1);
		
		printf("line %4i: %8s %10s  %10s    %10s  %10s", super->line,
			"iwrite", name, "", "", "");
		
		printf(" // (%s = %i)\n", name, vr->as_int);
		
		fflush(stdout);
		
		assert(vr->kind == vk_int);
	}
	#endif
	
	printf("%i\n", vr->as_int);
	
	*next = super->next;
	
	stats->total++;
}














