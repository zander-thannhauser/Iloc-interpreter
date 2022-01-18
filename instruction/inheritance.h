
#include <stdbool.h>

struct instruction;
union vregister;

struct instruction_inheritance
{
	void (*execute)(struct instruction*, bool, struct stats*, union vregister*, struct instruction**);
	void (*free)(struct instruction*);
};

