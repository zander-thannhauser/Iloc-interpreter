
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include <defines/argv0.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include <misc/get_vreg.h>

#include "struct.h"
#include "execute.h"

void iread_instruction_execute(
	struct instruction* super,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next)
{
	struct iread_instruction* const this = (typeof(this)) super;
	
	struct vregister* vr = get_vreg(stack, this->vr1);
	
	#ifdef ASM_VERBOSE
	char name[10];
	{
		snprintf(name, 10, "%%vr%u", this->vr1);
		
		printf("line %4i: %8s %10s  %10s    %10s  %10s", super->line,
			"iread", name, "", "", "");
		
		printf(" // (%s = %p)\n", name, vr->as_ptr);
		
		fflush(stdout);
		
		assert(vr->kind == vk_ptr || vr->kind == vk_int);
	}
	#endif
	
	int value;
	
	char* m;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	
	do if (printf("%%i> "), (nread = getline(&line, &len, stdin)) < 0)
		fprintf(stderr, "%s: getline: %m\n", argv0);
	else if (errno = 0, line[nread - 1] = '\0',
		value = strtol(line, &m, 10), errno || *m)
		fprintf(stderr, "%s: invalid int32 \"%s\"!\n", argv0, line);
	else break;
	while (1);
	
	if (!isatty(0))
		printf("%i\n", value);
	
	*vr->as_iptr = value;
	
	*next = super->next;
	
	stats->total++;
	
	free(line);
	
}











