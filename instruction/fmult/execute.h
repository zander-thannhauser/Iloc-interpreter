
struct instruction;
struct vregister;
struct stats;

void fmult_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* registers,
	struct vregister* parameters,
	struct instruction** next);
