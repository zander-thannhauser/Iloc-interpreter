
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
#include <misc/init_stack.h>

#include "print_stats.h"

int main(int argc, char** argv)
{
	int error = 0;
	struct cmdln_flags* flags = NULL;
	struct scope* scope = NULL;
	void* globals;
	size_t nregisters;
	size_t nparameters = 0;
	struct vregister* registers = NULL;
	struct vregister* parameters = NULL;
	struct instruction* i;
	struct stats stats = {};
	void* stack;
	ENTER;
	
	error = 0
		?: process_cmdln(&flags, argc, argv)
		?: new_scope(&scope)
		?: mmap_stack(&globals)
		?: parse(flags->in, scope, globals, &nregisters, &nparameters)
		?: scope_lookup_block(scope, "main", &i)
		?: scope_check_unresolved(scope)
		?: tcalloc((void**) &registers, nregisters, sizeof(*registers))
		?: tcalloc((void**) &parameters, nparameters, sizeof(*parameters))
		?: mmap_stack(&stack)
		?: init_stack(stack, registers);
		 ;
	
	if (!error) do
		execute_instruction(i, &stats, registers, parameters, &i);
	while (i);
	
	if (!error && flags->print_stats)
		print_stats(&stats);
	else if (error == e_show_usage)
		error = 0;
	
	tfree(registers);
	tfree(scope);
	tfree(flags);
	
	EXIT;
	return error;
}
















