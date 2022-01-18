
struct scope;
struct instruction;

int scope_lookup_block(
	struct scope* this,
	char* label,
	struct instruction** out);
