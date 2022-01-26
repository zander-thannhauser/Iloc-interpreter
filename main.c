
#include <enums/error.h>

#include <memory/tcalloc.h>
#include <memory/tfree.h>

#include <structs/stats.h>
#include <structs/stack.h>

#include <cmdln/flags.h>
#include <cmdln/process.h>

#include <scope/new.h>
#include <scope/block/struct.h>
#include <scope/lookup_block.h>
#include <scope/check_unresolved.h>

#include <parser/parse.h>

#include <instruction/execute.h>

#include <misc/mmap_stack.h>
/*#include <misc/init_stack.h>*/

#include "print_stats.h"

int main(int argc, char** argv)
{
	int error = 0;
	size_t nps = 0;
	struct cmdln_flags* flags = NULL;
	struct scope* scope = NULL;
	struct vregister* ps = NULL;
	struct block* b;
	struct stats stats = {};
	struct stack stack = {};
	ENTER;
	
	error = 0
		?: process_cmdln(&flags, argc, argv)
		?: new_scope(&scope)
		?: parse(flags->in, scope, &nps)
		?: scope_lookup_block(scope, "main", &b)
		?: scope_check_unresolved(scope)
		?: tcalloc((void**) &ps, nps, sizeof(*ps))
		?: mmap_stack(&stack.rsp.as_ptr)
		 ;
	
	if (!error)
	{
		#ifdef ASM_VERBOSE
		stack.rrp.kind = vk_ptr;
		stack.rbp.kind = vk_ptr;
		stack.rsp.kind = vk_ptr;
		#endif
		
		// the caller needs to push %rip:
		*stack.rsp.as_pptr-- = NULL;
		
		struct instruction* i = b->instruction;
		
		do execute_instruction(i, ps, &stack, &stats, &i); while (i);
		
		if (flags->print_stats)
			print_stats(&stats);
	}
	
	if (error == e_show_usage)
		error = 0;
	
	tfree(ps);
	tfree(scope);
	tfree(flags);
	
	EXIT;
	return error;
}
















