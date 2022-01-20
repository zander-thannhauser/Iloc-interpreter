
struct vregister_ll;

int new_icall_master_instruction(
	struct instruction** new,
	unsigned line,
	struct instruction* icall_masterme,
	struct vregister_ll* args,
	unsigned vr);
