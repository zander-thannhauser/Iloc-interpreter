

struct instruction;
struct vregister;
struct stats;
struct stack;

void cbr_LT_instruction_execute(
	struct instruction* this,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next);
