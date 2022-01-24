
#include <assert.h>
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void f2i_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* registers,
	struct vregister* parameters,
	struct instruction** next)
{
	struct f2i_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	char vr_src[10];
	char vr_dst[10];
	{
		snprintf(vr_src, 10, "%%vr%u", this->vr_src);
		snprintf(vr_dst, 10, "%%vr%u", this->vr_dst);
		
		printf("line %4i: %8s %10s  %10s => %-10s", super->line,
			"f2i", vr_src, "", vr_dst);
	}
	#endif
	
	registers[this->vr_dst].as_int = registers[this->vr_src].as_float;
	
	#ifdef ASM_VERBOSE
	{
		printf(" // (%s = %gf, %s = %i)\n",
			vr_src, registers[this->vr_src].as_float,
			vr_dst, registers[this->vr_dst].as_int);
	}
	#endif
	
	*next = super->next;
	
	stats->total++;
}









