
#include <debug.h>

#include "tokenizer.h"
#include "read_token.h"
#include "parse_data.h"
#include "parse_text.h"
#include "parse.h"

int parse(
	FILE* in,
	struct scope* scope,
	size_t* out_nregisters)
{
	int error = 0;
	ENTER;
	
	struct tokenizer t = { .in = in, .line = 1, .column = 0, .max_vreg = 4};
	
	error = 0
		?: read_token(&t)
		?: parse_data(&t, scope)
		?: parse_text(&t, scope, out_nregisters);
	
	dpv(t.max_vreg);
	*out_nregisters = t.max_vreg;
	
	if (!error && t.token != t_EOF)
		error = e_syntax_error;
	
	tfree(t.text.data);
	
	EXIT;
	return error;
}












