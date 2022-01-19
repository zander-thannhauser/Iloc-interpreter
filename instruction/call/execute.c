
#include <debug.h>

#include <macros/LAMBDA.h>

#include <structs/vregister.h>

#include <misc/vregister_ll/foreach.h>

#include "struct.h"
#include "execute.h"

void call_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	struct instruction** next)
{
	size_t i = 0, n = 0;
	struct call_instruction* this = (typeof(this)) super;
	
	if (debug)
	{
		printf("line %4i: %8s, %p", super->line, "call",
			this->callme);
		
		vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			printf(", %%vr%u", u);
		}));
		
		printf(" // (");
		
		vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			printf("%%vr%u = %i, ", u, rs[u].as_int);
			n++;
		}));
		
		printf(")\n");
	}
	
	union vregister tmp[n];
	
	vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
		tmp[i++] = rs[u];
	}));
	
	for (i = 0; i < n; i++)
		rs[i + 4] = tmp[i];
	
	// push %rip:
	{
		void** rsp = (void**) (int64_t) rs[1].as_int;
		*rsp = super->next;
		rs[1].as_int -= 8;
	}
	
	// jump:
	*next = this->callme;
}























