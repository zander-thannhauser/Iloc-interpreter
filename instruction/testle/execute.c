
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void testle_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct testle_instruction* const this = (typeof(this)) super;
	
	struct {
		#ifdef ASM_VERBOSE
		char name[10];
		char value[20];
		#endif
		struct vregister* reg;
	} in, out;
	
	 in.reg = get_vreg(stack, this->in);
	out.reg = get_vreg(stack, this->out);
	
	#ifdef ASM_VERBOSE
	{
		snprintf( in.name, 10, "%%vr%u", this->in);
		snprintf(out.name, 10, "%%vr%u", this->out);
		
		printf("line %4i: %8s %10s  %10s => %10s  %10s", super->line,
			"testle", in.name, "", out.name, "");
		
		printf(" // (%s = %s | ",
			in.name, print_vreg(in.value, in.reg));
		
		fflush(stdout);
		
		assert(in.reg->kind == vk_cmp);
	}
	#endif
	
	out.reg->as_int = in.reg->as_int <= 0;
	
	#ifdef ASM_VERBOSE
	{
		out.reg->kind = vk_bol;
		
		printf("%s = %s)\n", out.name, print_vreg(out.value, out.reg));
	}
	#endif
	
	*next = super->next;
	
	stats->comparisons++;
	stats->total++;
}

