
#include <stdbool.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <scope/block/struct.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void cbr_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct cbr_instruction* const this = (typeof(this)) super;
	
	struct vregister* conditional = get_vreg(stack, this->vr);
	
	#ifdef ASM_VERBOSE
	char name[10], value[10];
	{
		snprintf(name, 10, "%%vr%u", this->vr);
		
		printf("line %4i: %8s %10s  %10s -> %10s  %10s", super->line,
			"cbr", name, "", this->label->name, "");
		
		printf(" // (%s = %s | ", name, print_vreg(value, conditional));
	}
	#endif
	
	bool vr_value = conditional->as_int;
	
	*next = vr_value ? this->label->instruction : super->next;
	
	#ifdef ASM_VERBOSE
	{
		printf("%s = %u)\n", "line", (*next)->line);
	}
	#endif
	
	stats->total++;
}















