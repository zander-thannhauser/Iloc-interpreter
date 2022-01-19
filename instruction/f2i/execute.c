
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void f2i_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* registers,
	union vregister* parameters,
	struct instruction** next)
{
	char vr_src[10];
	char vr_dst[10];
	struct f2i_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		snprintf(vr_src, 10, "%%vr%u", this->vr_src);
		snprintf(vr_dst, 10, "%%vr%u", this->vr_dst);
		
		printf("line %4i: %8s %10s  %10s => %-10s", super->line,
			"f2i", vr_src, "", vr_dst);
	}
	
	registers[this->vr_dst].as_int = registers[this->vr_src].as_float;
	
	if (debug)
		printf(" // (%s = %gf, %s = %i)\n",
			vr_src, registers[this->vr_src].as_float,
			vr_dst, registers[this->vr_dst].as_int);
	
	*next = super->next;
	
	stats->total++;
}









