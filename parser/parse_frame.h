
struct tokenizer;
struct scope;

int parse_frame(
	struct tokenizer* t,
	struct scope* s,
	size_t* out_nparam_registers);
