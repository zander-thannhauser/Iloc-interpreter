
#include <debug.h>

#include <structs/vregister.h>

#include "struct.h"
#include "execute.h"

void ret_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	struct instruction** next)
{
	struct ret_instruction* const this = (typeof(this)) super;
	
	if (debug)
		printf("line %4u: %8s\n", super->line, "ret");
	
	/* movq %rbp, %rsp: */
	{
		rs[1].as_int = rs[0].as_int;
	}
	
	/* jump (pop %rsp):*/
	{
		rs[1].as_int += 8;
		
		void** rsp = (void**) (int64_t) rs[1].as_int;
		
		*next = *rsp;
	}
}












