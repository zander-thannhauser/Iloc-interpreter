
struct unresolved;
struct instruction;

int new_unresolved(
	struct unresolved** new,
	char* label,
	struct instruction* instruction);
