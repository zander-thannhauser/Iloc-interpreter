
#include <assert.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>

#include "struct.h"
#include "execute.h"

void fadd_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct fadd_instruction* const this = (typeof(this)) super;
	
	struct {
		#ifdef ASM_VERBOSE
		char name[10];
		char value[20];
		#endif
		struct vregister* reg;
	} vr1, vr2, vr3;

	vr1.reg = get_vreg(stack, this->vr1);
	vr2.reg = get_vreg(stack, this->vr2);
	vr3.reg = get_vreg(stack, this->vr3);
	
	#ifdef ASM_VERBOSE
	{
		snprintf(vr1.name, 10, "%%vr%u", this->vr1);
		snprintf(vr2.name, 10, "%%vr%u", this->vr2);
		snprintf(vr3.name, 10, "%%vr%u", this->vr3);
		
		printf("line %4i: %8s %10s, %10s => %10s  %10s", super->line,
			"fadd", vr1.name, vr2.name, vr3.name, "");
		
		fflush(stdout);
		
		assert(vr1.reg->kind == vk_flt);
		assert(vr2.reg->kind == vk_flt);
		
		printf(" // (%s = %gf, %s = %gf | ",
			vr1.name, vr1.reg->as_float,
			vr2.name, vr2.reg->as_float);
		
		fflush(stdout);
	}
	#endif
	
	vr3.reg->as_float = vr1.reg->as_float + vr2.reg->as_float;
	
	#ifdef ASM_VERBOSE
	{
		vr3.reg->kind = vk_flt;
		
		printf("%s = %gf)\n",
			vr3.name, vr3.reg->as_float);
	}
	#endif
	
	*next = super->next;
	
	stats->total++;
}











