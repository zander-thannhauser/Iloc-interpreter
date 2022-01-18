
#include <stddef.h>

int new_instruction(
	struct instruction** new,
	unsigned line,
	const struct instruction_inheritance* inheritance,
	size_t alloc_size);
