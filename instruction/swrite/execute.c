
#include <stdio.h>
#include <assert.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void swrite_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct swrite_instruction* const this = (typeof(this)) super;
	
	struct vregister* vr = get_vreg(stack, this->vr1);
	
	#ifdef ASM_VERBOSE
	char name[10];
	{
		snprintf(name, 10, "%%vr%u", this->vr1);
		
		printf("line %4i: %8s %10s  %10s    %10s  %10s", super->line,
			"swrite", name, "", "", "");
		
		printf(" // (%s == %p)\n",
			name, vr->as_ptr);
		
		fflush(stdout);
		
		assert(vr->kind == vk_ptr);
	}
	#endif
	
	puts(vr->as_cptr);
	
	*next = super->next;
	
	stats->total++;
}












