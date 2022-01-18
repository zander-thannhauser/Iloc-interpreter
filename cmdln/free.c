
#include "flags.h"
#include "free.h"

void free_cmdln_flags(void* ptr)
{
	struct cmdln_flags* const flags = ptr;
	ENTER;
	
	fclose(flags->in);

	EXIT;
}

