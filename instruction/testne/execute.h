
#include <stdbool.h>
struct instruction;
union vregister;
struct stats;

void testne_instruction_execute(
	struct instruction* super,
	bool debug,
	struct stats* stats,
	union vregister* registers,
	union vregister* parameters,
	struct instruction** next);
