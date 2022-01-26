
struct block;

int new_cbr_LT_instruction(
	struct instruction** new,
	unsigned line,
	unsigned vr1, unsigned vr2,
	struct block* label);
