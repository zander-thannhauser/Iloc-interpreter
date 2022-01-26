
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <scope/block/struct.h>

#include <misc/get_vreg.h>
#include <misc/print_vreg.h>

#include "struct.h"
#include "execute.h"

void cbr_LE_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct cbr_LE_instruction* const this = (typeof(this)) super;
	
	struct {
		#ifdef ASM_VERBOSE
		char name[10];
		char value[20];
		#endif
		struct vregister* reg;
	} vr1, vr2;

	vr1.reg = get_vreg(stack, this->vr1);
	vr2.reg = get_vreg(stack, this->vr2);

	#ifdef ASM_VERBOSE
	{
		snprintf(vr1.name, 10, "%%vr%u", this->vr1);
		snprintf(vr2.name, 10, "%%vr%u", this->vr2);
		
		printf("line %4i: %8s %10s, %10s -> %10s  %10s", super->line,
			"cbr_LE", vr1.name, vr2.name, this->label->name, "");
		
		printf(" // (%s = %s, %s = %s | ",
			vr1.name, print_vreg(vr1.value, vr1.reg),
			vr2.name, print_vreg(vr2.value, vr2.reg));
		
		fflush(stdout);
		
		assert(vr1.reg->kind == vk_int);
		assert(vr2.reg->kind == vk_int);
	}
	#endif
	
	*next = vr1.reg->as_int <= vr2.reg->as_int
		? this->label->instruction
		: super->next;
	
	#ifdef ASM_VERBOSE
	{
		printf("%s = %u)\n", "line", (*next)->line);
	}
	#endif
	
	stats->total++;
}









