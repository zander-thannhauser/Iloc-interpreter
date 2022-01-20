
#include <stdio.h>

#include <macros/LAMBDA.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/vregister_ll/foreach.h>

#include <instruction/frame/struct.h>

#include "struct.h"
#include "execute.h"

void call_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* ps,
	struct instruction** next)
{
	size_t i = 0, n = 0;
	struct call_instruction* this = (typeof(this)) super;
	
	TODO;
	#if 0
	if (debug)
	{
		printf("line %4i: %8s %10p", super->line, "call", this->callme);
		
		vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			char vr[10];
			snprintf(vr, 10, "%%vr%u", u);
			printf(", %10s", vr);
		}));
		
		printf(" // (");
		
		vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			printf("%%vr%u = %i, ", u, rs[u].as_int);
			n++;
		}));
		
		printf(")\n");
	}
	
	vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
		ps[i++] = rs[u];
	}));
	
	/* push %rip:    */ *rs[1].as_pptr-- = super->next;
	/* jump to call: */ *next            = this->callme;
	#endif
	
	stats->total++;
}























