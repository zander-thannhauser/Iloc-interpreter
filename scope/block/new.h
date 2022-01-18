
struct block;
struct instruction;

int new_block(
	struct block** new,
	char* label,
	struct instruction* instruction);
