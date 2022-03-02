
#include <sys/param.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void mult_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct mult_instruction* const this = (typeof(this)) super;
	
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
			"mult", vr1.name, vr2.name, vr3.name, "");
		
		printf(" // (%s = %s, %s = %s | ",
			vr1.name, print_vreg(vr1.value, vr1.reg),
			vr2.name, print_vreg(vr2.value, vr2.reg));
		
		fflush(stdout);
	}
	#endif
	
	vr3.reg->as_int = vr1.reg->as_int * vr2.reg->as_int;
	
	#ifdef ASM_VERBOSE
	{
		vr3.reg->kind = MAX(vr1.reg->kind, vr2.reg->kind);
		
		printf("%s = %s)\n", vr3.name, print_vreg(vr3.value, vr3.reg));
	}
	#endif
	
	stats->mults++;
	stats->total++;
	
	*next = super->next;
}














