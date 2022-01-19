
struct tokenizer;
struct scope;

int parse_data(
	struct tokenizer* t,
	void* globals,
	struct scope* scope);
