
struct instruction
{
	const struct instruction_inheritance* inheritance;
	
	unsigned line;
	
	struct instruction* next;
};

