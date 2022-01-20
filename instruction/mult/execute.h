
#include <stdbool.h>

struct instruction;
struct vregister;
struct stats;

void mult_instruction_execute(
	struct instruction* super,
	struct stats* stats,
	struct vregister* registers,
	struct vregister* parameters,
	struct instruction** next);
