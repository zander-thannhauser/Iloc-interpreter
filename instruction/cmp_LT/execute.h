
struct instruction;
struct vregister;
struct stats;
struct stack;

void cmp_LT_instruction_execute(
	struct instruction* this,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next);
