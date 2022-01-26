
struct instruction;
struct stats;
struct vregister;
struct stack;

void execute_instruction(
	struct instruction* this,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next);
