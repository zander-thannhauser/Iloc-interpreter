
#include <assert.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void i2f_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* registers,
	struct vregister* parameters,
	struct instruction** next)
{
	struct i2f_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	char vr_src[10];
	char vr_dst[10];
	{
		snprintf(vr_src, 10, "%%vr%u", this->vr_src);
		snprintf(vr_dst, 10, "%%vr%u", this->vr_dst);
		
		printf("line %4i: %8s %10s  %10s => %-10s", super->line,
			"i2f", vr_src, "", vr_dst);
	}
	#endif
	
	registers[this->vr_dst].as_float = registers[this->vr_src].as_int;
	
	#ifdef ASM_VERBOSE
	{
		printf(" // (%s = %i, %s = %gf)\n",
			vr_src, registers[this->vr_src].as_int,
			vr_dst, registers[this->vr_dst].as_float);
	}
	#endif
	
	stats->total++;
	
	*next = super->next;
}









