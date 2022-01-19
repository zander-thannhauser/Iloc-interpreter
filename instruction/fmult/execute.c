
#include <debug.h>

#include <structs/vregister.h>

#include "struct.h"
#include "execute.h"

void fmult_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	struct instruction** next)
{
	TODO;
	#if 0
	char vr1[10];
	char vr2[10];
	char vr3[10];
	struct fmult_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		snprintf(vr3, 10, "%%vr%u", this->vr3);
		
		printf("line %4i: %8s %8s, %8s => %-16s", super->line,
			"fmult", vr1, vr2, vr3);
	}
	
	int32_t vr1_backup = rs[this->vr1].as_int;
	int32_t vr2_backup = rs[this->vr2].as_int;
	int32_t vr3_backup = vr1_backup * vr2_backup;
	
	rs[this->vr3].as_int = vr3_backup;
	
	if (debug)
	{
		printf(" // (%s = %i, %s = %i, %s = %i)\n",
			vr1, vr1_backup,
			vr2, vr2_backup,
			vr3, vr3_backup);
	}
	#endif
	
	*next = super->next;
}

