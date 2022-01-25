
#include <enums/error.h>

#include <memory/tcalloc.h>
#include <memory/tfree.h>

#include <structs/stats.h>
#include <structs/vregister.h>

#include <cmdln/flags.h>
#include <cmdln/process.h>

#include <scope/new.h>
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
	struct cmdln_flags* flags = NULL;
	struct scope* scope = NULL;
	size_t nparameters = 0;
	struct vregister* rbp, *rsp;
	struct vregister* parameters = NULL;
	struct instruction* i;
	struct stats stats = {};
	void* stack;
	ENTER;
	
/*	putchar('\n');*/
	
	error = 0
		?: process_cmdln(&flags, argc, argv)
		?: new_scope(&scope)
		?: parse(flags->in, scope, globals, &nparameters)
		?: scope_lookup_block(scope, "main", &i)
		?: scope_check_unresolved(scope)
		?: tcalloc((void**) &parameters, nparameters, sizeof(*parameters))
		?: mmap_stack(&registers)
		?: mmap_stack(&stack)
/*		?: init_stack(stack, registers)*/
		 ;
	
	if (!error)
	{
		TODO;
		#if 0
		
		#ifdef ASM_VERBOSE
		rs[0].kind   = vk_ptr;
		rs[1].kind   = vk_ptr;
		#endif
		
		// set %rsp:
		{
			rs[1].as_ptr = stack;
		}
		
		// the caller needs to push %rip:
		{
			*rs[1].as_pptr-- = NULL;
		}
	
		#endif
		
		// set up register {stack,base} pointer
		TODO;
		
		do execute_instruction(i, &stats, &rbp, &rsp, parameters, &i);
		while (i);
		
		if (flags->print_stats)
			print_stats(&stats);
	}
	
	if (error == e_show_usage)
		error = 0;
	
	tfree(registers);
	tfree(parameters);
	tfree(scope);
	tfree(flags);
	
	EXIT;
	return error;
}
















