
#include <debug.h>

#include <structs/vregister.h>

#include "struct.h"
#include "execute.h"

void fload_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* registers,
	struct instruction** next)
{
	TODO;
	#if 0
	char vr1[10];
	char vr2[10];
	struct fload_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		
		printf("line %4i: %8s %8s  %8s => %-16s", super->line,
			"fload", vr1, "", vr2);
	}
	
	int32_t* ptr = (int32_t*) (int64_t) registers[this->vr1].as_int;
	
	int32_t vr2_value = *ptr;
	
	registers[this->vr2].as_int = vr2_value;
	
	if (debug)
		printf(" // (%s = %p, *%s = %i, %s = %i)\n",
			vr1,  ptr,
			vr1, *ptr,
			vr2,  vr2_value);
	#endif
	
	*next = super->next;
}












