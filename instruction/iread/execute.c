
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include <defines/argv0.h>

#include <structs/vregister.h>
#include <structs/stats.h>

#include "struct.h"
#include "execute.h"

void iread_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* rs,
	struct vregister* parameters,
	struct instruction** next)
{
	struct iread_instruction* const this = (typeof(this)) super;
	
	#ifdef ASM_VERBOSE
	char vr1[10];
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		
		printf("line %4i: %8s %10s  %10s    %10s  %10s", super->line,
			"iread", vr1, "", "", "");
		
		rs[this->vr1].kind = vk_ptr;
		
		printf(" // (%s = %p)\n", vr1, rs[this->vr1].as_ptr);
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
	
	*rs[this->vr1].as_iptr = value;
	
	*next = super->next;
	
	stats->total++;
	
	free(line);
	
}











