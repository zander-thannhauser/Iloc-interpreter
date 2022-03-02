
#include <assert.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>

#include "struct.h"
#include "execute.h"

void load_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct load_instruction* const this = (typeof(this)) super;
	
	struct {
		#ifdef ASM_VERBOSE
		char name[10];
		char value[20];
		#endif
		struct vregister* reg;
	} src, val;

	src.reg = get_vreg(stack, this->src);
	val.reg = get_vreg(stack, this->val);
	
	#ifdef ASM_VERBOSE
	{
		snprintf(src.name, 10, "%%vr%u", this->src);
		snprintf(val.name, 10, "%%vr%u", this->val);
		
		printf("line %4i: %8s %10s  %10s => %10s  %10s", super->line,
			"load", src.name, "", val.name, "");
		
		printf(" // (%s = %p, *%s = %i | ",
			src.name,  src.reg->as_iptr,
			src.name, *src.reg->as_iptr);
		
		fflush(stdout);
		
		assert(src.reg->kind == vk_ptr || src.reg->kind == vk_int);
	}
	#endif
	
	val.reg->as_int = *src.reg->as_iptr;
	
	#ifdef ASM_VERBOSE
	{
		val.reg->kind = vk_int;
		
		printf("%s = %i)\n",
			val.name, val.reg->as_int);
	}
	#endif
	
	stats->loads++;
	stats->total++;
	
	*next = super->next;
}












