
#include <assert.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void i2f_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct i2f_instruction* const this = (typeof(this)) super;
	
	struct {
		#ifdef ASM_VERBOSE
		char name[10];
		char value[20];
		#endif
		struct vregister* reg;
	} src, dst;
	
	src.reg = get_vreg(stack, this->src);
	dst.reg = get_vreg(stack, this->dst);
	
	#ifdef ASM_VERBOSE
	{
		snprintf(src.name, 10, "%%vr%u", this->src);
		snprintf(dst.name, 10, "%%vr%u", this->dst);
		
		printf("line %4i: %8s %10s  %10s => %10s  %10s", super->line,
			"i2f", src.name, "", dst.name, "");
		
		printf(" // (%s = %s | ",
			src.name, print_vreg(src.value, src.reg));
		
		fflush(stdout);
		
		assert(src.reg->kind == vk_int);
	}
	#endif
	
	dst.reg->as_float = src.reg->as_int;
	
	#ifdef ASM_VERBOSE
	{
		dst.reg->kind = vk_flt;
		
		printf("%s = %s)\n",
			dst.name, print_vreg(dst.value, dst.reg));
	}
	#endif
	
	stats->total++;
	
	*next = super->next;
	
}









