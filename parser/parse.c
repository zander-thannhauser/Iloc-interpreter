

#include <defines/argv0.h>

#include <enums/error.h>

#include <memory/tfree.h>

#include "tokenizer.h"
#include "read_token.h"
#include "parse_data.h"
#include "parse_text.h"
#include "parse.h"

int parse(
	FILE* in,
	struct scope* scope,
	void* globals,
	size_t* out_nregisters,
	size_t* out_nparameters)
{
	int error = 0;
	ENTER;
	
	struct tokenizer t = { .in = in, .line = 1, .max_vreg = 4};
	
	error = 0
		?: read_token(&t)
		?: parse_data(&t, globals, scope)
		?: parse_text(&t, scope, out_nregisters, out_nparameters);
	
	dpv(t.max_vreg);
	
	*out_nregisters = t.max_vreg;
	
	dpv(*out_nparameters);
	
	if (!error && t.token != t_EOF)
		error = e_syntax_error;
	
	if (error == e_syntax_error)
	{
		fprintf(stderr, "%s: syntax error on line %u\n", argv0, t.token_line);
	}
	
	tfree(t.text.data);
	
	EXIT;
	return error;
}












