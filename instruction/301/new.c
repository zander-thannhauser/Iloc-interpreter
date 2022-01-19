
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_301_instruction(struct instruction** new)
{
	int error = 0;
	ENTER;
	
	struct _301_instruction* this;
	
	error = new_instruction(
		/* instance: */ (struct instruction**) &this,
		/* line: */ 0,
		/* inheritance: */ &_301_instruction_inheritance,
		/* size: */ sizeof(*this));
	
	if (!error)
	{
		dpv(this);
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















