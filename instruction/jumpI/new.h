
struct block;

int new_jumpI_instruction(
	struct instruction** new,
	unsigned line,
	struct block* label);
