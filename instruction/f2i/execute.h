
struct instruction;
struct vregister;
struct stats;

void f2i_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* registers,
	struct vregister* parameters,
	struct instruction** next);
