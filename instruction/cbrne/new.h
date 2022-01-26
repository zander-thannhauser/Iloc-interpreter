
struct block;

int new_cbrne_instruction(
	struct instruction** new,
	unsigned line,
	unsigned vr,
	struct block* label);
