
#include <debug.h>

#include <structs/vregister.h>

#include "struct.h"
#include "execute.h"

void store_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	struct instruction** next)
{
	char vr1[10];
	char vr2[10];
	struct store_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		snprintf(vr2, 10, "%%vr%u", this->vr2);
		
		printf("line %4i: %8s %8s  %8s => %-16s", super->line,
			"store", vr1, "", vr2);
	}
	
	int32_t vr1_value = rs[this->vr1].as_int;
	
	int32_t* ptr = (int32_t*) (int64_t) rs[this->vr2].as_int;
	
	*ptr = vr1_value;
	
	if (debug)
		printf(" // (%s = %i, %s = %p, *%s = %i)\n",
			vr1,  vr1_value,
			vr2,  ptr,
			vr2, *ptr);
	
	*next = super->next;
}

















