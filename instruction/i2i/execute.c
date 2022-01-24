
#include <stdio.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void i2i_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	struct i2i_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	char vr_src[10];
	char vr_dst[10];
	
	snprintf(vr_src, 10, "%%vr%u", this->vr_src);
	snprintf(vr_dst, 10, "%%vr%u", this->vr_dst);
	
	printf("line %4i: %8s %10s  %10s => %10s  %10s", super->line,
		"i2i", vr_src, "", vr_dst, "");
	#endif
	
	rs[this->vr_dst] = rs[this->vr_src];
	
	#ifdef ASM_VERBOSE
	printf(" // (%s = %s, ", vr_src, print_vreg(&rs[this->vr_src]));
	
	printf("%s = %s)\n", vr_dst, print_vreg(&rs[this->vr_dst]));
	#endif
	
	stats->total++;
	
	*next = super->next;
}









