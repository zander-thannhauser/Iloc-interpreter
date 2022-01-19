
#include <stdio.h>
#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void i2f_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* registers,
	union vregister* parameters,
	struct instruction** next)
{
	char vr_src[10];
	char vr_dst[10];
	struct i2f_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		snprintf(vr_src, 10, "%%vr%u", this->vr_src);
		snprintf(vr_dst, 10, "%%vr%u", this->vr_dst);
		
		printf("line %4i: %8s %10s  %10s => %-10s", super->line,
			"i2f", vr_src, "", vr_dst);
	}
	
	registers[this->vr_dst].as_float = registers[this->vr_src].as_int;
	
	if (debug)
		printf(" // (%s = %i, %s = %gf)\n",
			vr_src, registers[this->vr_src].as_int,
			vr_dst, registers[this->vr_dst].as_float);
	
	stats->total++;
	
	*next = super->next;
}









