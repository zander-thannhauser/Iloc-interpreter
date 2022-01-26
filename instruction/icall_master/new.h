
struct block;
struct vregister_ll;

int new_icall_master_instruction(
	struct instruction** new,
	unsigned line,
	struct block* callme,
	struct vregister_ll* args,
	unsigned vr);
