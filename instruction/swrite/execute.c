
#include <debug.h>

#include <structs/vregister.h>

#include "struct.h"
#include "execute.h"

void swrite_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	struct instruction** next)
{
	TODO;
	#if 0
	char vr1[10];
	struct swrite_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		
		printf("line %4i: %8s %8s  %8s    %-16s\n", super->line,
			"swrite", vr1, "", "");
	}
	
	int32_t vr_value = rs[this->vr1].as_int;
	
	printf("%i\n", vr_value);
	#endif
	
	*next = super->next;
}

