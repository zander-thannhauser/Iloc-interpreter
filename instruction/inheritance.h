
#include <stdbool.h>

struct instruction;
struct vregister;
struct stats;

struct instruction_inheritance
{
	void (*execute)(struct instruction*, struct stats*, struct vregister*, struct vregister*, struct instruction**);
	void (*free)(struct instruction*);
};

