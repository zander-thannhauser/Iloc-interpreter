
struct vregister_ll;

int new_call_instruction(
	struct instruction** new,
	unsigned line,
	struct block* callme,
	struct vregister_ll* args);
