
#include <stdio.h>

#include <macros/LAMBDA.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/vregister_ll/foreach.h>

#include <instruction/frame/struct.h>

#include "struct.h"
#include "execute.h"

void icall_slave_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* ps,
	struct instruction** next)
{
	struct icall_slave_instruction* this = (typeof(this)) super;
	
	rs[this->vr].as_int = ps[0].as_int;
	
	*next = super->next;
}























