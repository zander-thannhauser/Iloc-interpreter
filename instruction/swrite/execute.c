
#include <assert.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void swrite_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	union vregister* parameters,
	struct instruction** next)
{
	char vr1[10];
	struct swrite_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		
		printf("line %4i: %8s %10s  %10s    %-10s\n", super->line,
			"swrite", vr1, "", "");
	}
	
	char* vr_value = rs[this->vr1].as_cptr;
	
	puts(vr_value);
	
	*next = super->next;
	
	stats->total++;
}

