
struct instruction;
struct vregister;
struct stats;

void frame_instruction_execute(struct instruction* this,
	struct stats* stats,
	struct vregister* registers,
	struct vregister* parameters,
	struct instruction** next);
