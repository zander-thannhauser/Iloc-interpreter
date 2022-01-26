
struct scope;
struct block;

int scope_lookup_block(
	struct scope* this,
	char* label,
	struct block** out);
