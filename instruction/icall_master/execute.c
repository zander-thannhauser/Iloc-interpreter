
#include <stdio.h>

#include <macros/LAMBDA.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/vregister_ll/foreach.h>

#include <instruction/frame/struct.h>

#include "struct.h"
#include "execute.h"

void icall_master_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* rs,
	union vregister* ps,
	struct instruction** next)
{
	size_t i = 0, n = 0;
	struct icall_master_instruction* this = (typeof(this)) super;
	
	if (debug)
	{
		printf("line %4i: %8s %10p", super->line, "icall", this->callme);
		
		vregister_ll_foreach(this->args, LAMBDA((unsigned u), {
			char vr[10];
			snprintf(vr, 10, "%%vr%u", u);
			printf(", %10s", vr);
		}));
		
		printf(" => %%vr%u", this->vr);
		
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
	
	/* push %rip:      */ *rs[1].as_pptr-- = super->next;
	/* jump to callme: */ *next            = this->callme;
	
	stats->total++;
}






















