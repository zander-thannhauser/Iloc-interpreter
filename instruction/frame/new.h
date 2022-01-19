
#include <stddef.h>

struct vregister_ll;

int new_frame_instruction(
	struct instruction** new,
	unsigned line,
	char* name,
	size_t frame_size,
	struct vregister_ll* args);
