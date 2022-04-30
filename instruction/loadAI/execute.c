
#include <assert.h>

#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void loadAI_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct loadAI_instruction* const this = (typeof(this)) super;
		
	struct {
		#ifdef ASM_VERBOSE
		char name[10];
		char value[20];
		#endif
		struct vregister* reg;
	} vr1, vr3;

	vr1.reg = get_vreg(stack, this->vr1);
	vr3.reg = get_vreg(stack, this->vr3);

	#ifdef ASM_VERBOSE
	{
		snprintf(vr1.name, 10, "%%vr%u", this->vr1);
		snprintf(vr3.name, 10, "%%vr%u", this->vr3);
		
		printf("line %4i: %8s %10s, %10i => %10s  %10s", super->line,
			"loadAI", vr1.name, this->intlit, vr3.name, "");
		
		printf(" // (%s = %s | %p + %i = %p | ",
			vr1.name, print_vreg(vr1.value, vr1.reg),
			vr1.reg->as_ptr, this->intlit,
			vr1.reg->as_ptr + this->intlit);
		
		fflush(stdout);
		
/*		assert(vr1.reg->kind == vk_ptr);*/
	}
	#endif
	
	int* vr1_value = vr1.reg->as_ptr + this->intlit;
	
	vr3.reg->as_int = *vr1_value;
	
	#ifdef ASM_VERBOSE
	{
		vr3.reg->kind = vk_int;
		
		printf("*%p = %i, %s = %i)\n",
			vr1_value, *vr1_value,
			vr3.name,  vr3.reg->as_int);
	}
	#endif
	
	stats->loads++;
	stats->total++;
	
	*next = super->next;
}












