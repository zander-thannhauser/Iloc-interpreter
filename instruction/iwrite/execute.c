
#include <debug.h>

#include <structs/vregister.h>

#include "struct.h"
#include "execute.h"

void iwrite_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	struct instruction** next)
{
	char vr1[10];
	struct iwrite_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		
		printf("line %4i: %8s %8s  %8s    %-16s\n", super->line,
			"iwrite", vr1, "", "");
	}
	
	int32_t vr_value = rs[this->vr1].as_int;
	
	printf("%i\n", vr_value);
	
	*next = super->next;
}

