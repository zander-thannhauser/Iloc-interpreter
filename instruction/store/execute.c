
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void store_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct store_instruction* const this = (typeof(this)) super;
	
	struct {
		#ifdef ASM_VERBOSE
		char name[10];
		char value[20];
		#endif
		struct vregister* reg;
	} val, dst;

	val.reg = get_vreg(stack, this->vr1);
	dst.reg = get_vreg(stack, this->vr2);
	
	#ifdef ASM_VERBOSE
	{
		snprintf(val.name, 10, "%%vr%u", this->vr1);
		snprintf(dst.name, 10, "%%vr%u", this->vr2);
		
		printf("line %4i: %8s %10s  %10s => %10s  %10s", super->line,
			"store", val.name, "", dst.name, "");
		
		assert(dst.reg->kind == vk_ptr);
		
		printf(" // (%s = %s, %s = %p | ",
			val.name, print_vreg(val.value, val.reg),
			dst.name, print_vreg(dst.value, val.reg));
		
		fflush(stdout);
	}
	#endif
	
	*dst.reg->as_iptr = val.reg->as_int;
	
	#ifdef ASM_VERBOSE
	{
		printf("*%s = %s)\n",
			dst.name, val.value);
	}
	#endif
	
	stats->stores++;
	stats->total++;
	
	*next = super->next;
}

















