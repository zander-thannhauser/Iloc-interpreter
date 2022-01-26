
#include <assert.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void storeAO_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct storeAO_instruction* const this = (typeof(this)) super;
	
	struct {
		#ifdef ASM_VERBOSE
		char name[10];
		char value[20];
		#endif
		struct vregister* reg;
	} val, dst, off;
	
	val.reg = get_vreg(stack, this->val);
	dst.reg = get_vreg(stack, this->dst);
	off.reg = get_vreg(stack, this->off);
	
	#ifdef ASM_VERBOSE
	{
		snprintf(val.name, 10, "%%vr%u", this->val);
		snprintf(dst.name, 10, "%%vr%u", this->dst);
		snprintf(off.name, 10, "%%vr%u", this->off);
		
		printf("line %4i: %8s %10s  %10s => %10s, %10s", super->line,
			"storeAO", val.name, "", dst.name, off.name);
		
		printf(" // (%s = %s, %s = %s, %s = %s, %s + %s = %p | ",
			val.name, print_vreg(val.value, val.reg),
			dst.name, print_vreg(dst.value, dst.reg),
			off.name, print_vreg(off.value, off.reg),
			dst.name, off.name, dst.reg->as_ptr + off.reg->as_int);
		
		fflush(stdout);
		
		assert(dst.reg->kind == vk_ptr);
	}
	#endif
	
	int  vr1_value = val.reg->as_int;
	int* vr2_value = dst.reg->as_ptr + off.reg->as_int;
	
	*vr2_value = vr1_value;
	
	#ifdef ASM_VERBOSE
	{
		printf("*%p = %i)\n",
			dst.reg->as_ptr + off.reg->as_int, vr1_value);
	}
	#endif
	
	stats->stores++;
	stats->total++;
	
	*next = super->next;
}

















