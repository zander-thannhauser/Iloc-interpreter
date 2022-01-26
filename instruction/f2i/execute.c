
#include <assert.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>

#include "struct.h"
#include "execute.h"

void f2i_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct f2i_instruction* const this = (typeof(this)) super;
	
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
			"f2i", src.name, "", dst.name, "");
		
		assert(src.reg->kind == vk_flt);
		
		printf(" // (%s = %gf | ",
			src.name, src.reg->as_float);
		
		fflush(stdout);
	}
	#endif
	
	dst.reg->as_int = src.reg->as_float;
	
	#ifdef ASM_VERBOSE
	{
		dst.reg->kind = vk_int;
		
		printf("%s = %i)\n",
			dst.name, dst.reg->as_int);
	}
	#endif
	
	*next = super->next;
	
	stats->total++;
}









