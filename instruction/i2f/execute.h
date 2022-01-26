
struct instruction;
struct vregister;
struct stats;
struct stack;

void i2f_instruction_execute(
	struct instruction* this,
	struct vregister* ps,
	struct stack* stack,
	struct stats* stats,
	struct instruction** next);
