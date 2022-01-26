
#include <stdbool.h>

struct instruction;
struct vregister;
struct stats;
struct stack;

struct instruction_inheritance
{
	void (*execute)(
		struct instruction* this,
		struct vregister* ps,
		struct stack* stack,
		struct stats* stats,
		struct instruction** next);
	
	void (*free)(struct instruction*);
};

