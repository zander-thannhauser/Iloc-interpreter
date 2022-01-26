

struct instruction;
struct vregister;
struct stack;
struct stats;

void call_instruction_execute(
	struct instruction* this,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next);
