

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
	size_t* out_nps)
{
	int error = 0;
	ENTER;
	
	struct tokenizer t = { .in = in, .line = 1};
	
	error = 0
		?: read_token(&t)
		?: parse_data(&t, scope)
		?: parse_text(&t, scope, out_nps)
		 ;
	
	dpv(*out_nps);
	
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












