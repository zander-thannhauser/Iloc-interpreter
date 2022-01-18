
#include <debug.h>

#include <structs/vregister.h>

#include "struct.h"
#include "execute.h"

void frame_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	struct instruction** next)
{
	struct frame_instruction* const this = (typeof(this)) super;
	
	if (debug)
		printf("line %4u: %8s %8s, %8zu    %-16s", super->line,
		"frame", this->name, this->frame_size, "");
	
	/* pushq %rbp:*/
	{
		int64_t* rsp = (int64_t*)(int64_t) rs[1].as_int;
		*rsp = rs[0].as_int;
		rs[1].as_int++;
	}
	
	/* movq %rsp, %rbp: */
	{
		rs[0].as_int = rs[1].as_int;
	}
	
	/* subq fs, %rsp: */
	{
		rs[1].as_int -= this->frame_size;
	}
	
	if (debug)
		printf(" // (%%vr0 = 0x%X, %%vr1 = 0x%X)\n",
		rs[0].as_int, rs[1].as_int);
	
	// eventually there'll be arguments to handle here
	
	*next = super->next;
}


















