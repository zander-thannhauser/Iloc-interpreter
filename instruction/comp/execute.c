
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void comp_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct comp_instruction* const this = (typeof(this)) super;
	
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
			"comp", vr1.name, vr2.name, vr3.name, "");
		
		printf(" // (%s = %s, %s = %s | ",
			vr1.name, print_vreg(vr1.value, vr1.reg),
			vr2.name, print_vreg(vr2.value, vr2.reg));
		
		fflush(stdout);
		
		assert(vr1.reg->kind == vk_int || vr1.reg->kind == vk_bol);
		assert(vr2.reg->kind == vk_int || vr2.reg->kind == vk_bol);
	}
	#endif
	
	int vr1_value = vr1.reg->as_int;
	int vr2_value = vr2.reg->as_int;
	int vr3_value;
	
	if (vr1_value > vr2_value)
		vr3_value = +1;
	else if (vr1_value < vr2_value)
		vr3_value = -1;
	else
		vr3_value = 0;
	
	vr3.reg->as_int = vr3_value;
	
	#ifdef ASM_VERBOSE
	{
		vr3.reg->kind = vk_cmp;
		
		printf("%s = %s)\n",
			vr3.name, print_vreg(vr3.value, vr3.reg));
	}
	#endif
	
	*next = super->next;
	
	stats->comparisons++;
	stats->total++;
}













