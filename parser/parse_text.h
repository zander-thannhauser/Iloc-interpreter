
struct tokenizer;
struct scope;

int parse_text(
	struct tokenizer* t,
	struct scope* scope,
	size_t* out_nregisters,
	size_t* out_nparam_registers);
