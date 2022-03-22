
#include <assert.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <scope/block/struct.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void cbrne_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct cbrne_instruction* const this = (typeof(this)) super;
	
	struct vregister* vr = get_vreg(stack, this->vr);
	
	#ifdef ASM_VERBOSE
	char name[10], value[10];
	{
		snprintf(name, 10, "%%vr%u", this->vr);
		
		printf("line %4i: %8s %10s  %10s -> %10s  %10s", super->line,
			"cbrne", name, "", this->label->name, "");
		
		printf(" // (%s = %s | ",
			name, print_vreg(value, vr));
		
		fflush(stdout);
		
		assert(vr->kind == vk_bol || vr->kind == vk_int);
		
	}
	#endif
	
	*next = !vr->as_int
		? this->label->instruction
		: super->next;
	
	#ifdef ASM_VERBOSE
	{
		printf("%s = %u)\n",
			"line", (*next)->line);
	}
	#endif
	
	stats->total++;
}










