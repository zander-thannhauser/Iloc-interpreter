
struct instruction;
struct stats;
union vregister;

void execute_instruction(
	struct instruction* this,
	bool debug,
	struct stats* stats,
	union vregister* registers,
	struct instruction** next);
