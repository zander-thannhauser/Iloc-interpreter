
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
	TODO;
	#if 0
	char vr1[10];
	struct iread_instruction* const this = (typeof(this)) super;
	
	if (debug)
	{
		snprintf(vr1, 10, "%%vr%u", this->vr1);
		
		printf("line %4i: %8s %10s\n", super->line, "iread", vr1);
	}
	
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
	#endif
	
}











