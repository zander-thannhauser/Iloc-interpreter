
#include <assert.h>
#include <stdio.h>

#include <macros/LAMBDA.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>

#include <instruction/frame/struct.h>

#include "struct.h"
#include "execute.h"

void icall_slave_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct icall_slave_instruction* this = (typeof(this)) super;
	
	struct vregister* vr = get_vreg(stack, this->vr);
	
	#ifdef ASM_VERBOSE
	vr->kind = vk_int;
	#endif
	
	vr->as_int = ps[0].as_int;
	
	*next = super->next;
	
}























