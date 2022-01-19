
#include <macros/streq.h>

#include "tokenizer.h"
#include "read_token.h"

#include "parse_frame.h"
#include "parse_text.h"

int parse_text(
	struct tokenizer* t,
	struct scope* s,
	size_t* out_nregisters,
	size_t* out_nparameters)
{
	int error = 0;
	ENTER;
	
	if (t->token == t_text)
	{
		error = read_token(t);
		
		while (!error && t->token == t_frame)
		{
			error = parse_frame(t, s, out_nparameters);
		}
	}
	
	EXIT;
	return error;
}





















