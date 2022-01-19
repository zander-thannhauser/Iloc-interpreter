

#include <stdbool.h>
struct instruction;
union vregister;
struct stats;

void frame_instruction_execute(struct instruction* this,
	bool debug,
	struct stats* stats,
	union vregister* registers,
	union vregister* parameters,
	struct instruction** next);
