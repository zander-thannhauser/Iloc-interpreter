
#include <assert.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void storeAI_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct storeAI_instruction* const this = (typeof(this)) super;
	
	struct {
		#ifdef ASM_VERBOSE
		char name[10];
		char value[20];
		#endif
		struct vregister* reg;
	} val, dst;

	val.reg = get_vreg(stack, this->val);
	dst.reg = get_vreg(stack, this->dst);

	#ifdef ASM_VERBOSE
	{
		snprintf(val.name, 10, "%%vr%u", this->val);
		snprintf(dst.name, 10, "%%vr%u", this->dst);
		
		printf("line %4i: %8s %10s  %10s => %10s, %10i", super->line,
			"storeAI", val.name, "", dst.name, this->index);
		
		printf(" // (%s = %s, %s = %s | ",
			val.name, print_vreg(val.value, val.reg),
			dst.name, print_vreg(dst.value, dst.reg));
		
		fflush(stdout);
		
/*		assert(dst.reg->kind == vk_ptr);*/
	}
	#endif
	
	int  vr1_value = val.reg->as_int;
	int* vr2_value = dst.reg->as_ptr + this->index;
	
	*vr2_value = vr1_value;
	
	#ifdef ASM_VERBOSE
	{
		printf("%p + %i = %p, *%p = %i)\n",
			dst.reg->as_ptr, this->index, vr2_value,
			vr2_value, vr1_value);
	}
	#endif
	
	stats->stores++;
	stats->total++;
	
	*next = super->next;
}

















