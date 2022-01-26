
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void i2i_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct i2i_instruction* const this = (typeof(this)) super;

	struct {
		#ifdef ASM_VERBOSE
		char name[10];
		char value[20];
		#endif
		struct vregister* reg;
	} src, dst;
	
	src.reg = get_vreg(stack, this->vr_src);
	dst.reg = get_vreg(stack, this->vr_dst);
	
	#ifdef ASM_VERBOSE
	snprintf(src.name, 10, "%%vr%u", this->vr_src);
	snprintf(dst.name, 10, "%%vr%u", this->vr_dst);
	
	printf("line %4i: %8s %10s  %10s => %10s  %10s", super->line,
		"i2i", src.name, "", dst.name, "");
	
	printf(" // (%s = %s | ",
		src.name, print_vreg(src.value, src.reg));
	
	fflush(stdout);
	
	#endif
	
	*dst.reg = *src.reg;
	
	#ifdef ASM_VERBOSE
	
	printf("%s = %s)\n",
		dst.name, print_vreg(dst.value, dst.reg));
	
	#endif
	
	stats->total++;
	
	*next = super->next;
}









