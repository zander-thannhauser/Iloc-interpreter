
struct instruction;
struct stats;
struct vregister;

void execute_instruction(
	struct instruction* this,
	struct stats* stats,
	struct vregister* registers,
	struct vregister* pregisters,
	struct instruction** next);
