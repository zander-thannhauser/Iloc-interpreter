
#ifndef STRUCT_INSTRUCTION_H
#define STRUCT_INSTRUCTION_H

struct instruction
{
	const struct instruction_inheritance* inheritance;
	
	unsigned line;
	
	struct instruction* next;
};

#endif
