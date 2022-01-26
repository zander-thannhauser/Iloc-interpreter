
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void loadI_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct loadI_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	char vr[10];
	char value[20];
	
	snprintf(vr, 10, "%%vr%u", this->vr);
	
	print_vreg(value, &this->literal);
	
	printf("line %4i: %8s %10s  %10s => %10s  %10s",
		super->line, "loadI", value, "", vr, "");
	
	fflush(stdout);
	#endif
	
	struct vregister* dst = get_vreg(stack, this->vr);
	
	*dst = this->literal;
	
	#ifdef ASM_VERBOSE
	printf(" // (%%vr%u = %s)\n", this->vr, value);
	#endif
	
	*next = super->next;
	
	stats->total++;
}















