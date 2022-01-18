
#include <debug.h>

#include <macros/streq.h>

#include <scope/declare_global.h>

#include "tokenizer.h"
#include "read_token.h"
#include "parse_data.h"

int parse_data(
	struct tokenizer* t,
	struct scope* scope)
{
	int error = 0;
	ENTER;
	
	if (t->token == t_data)
	{
		bool keep_going = true;
		
		error = read_token(t);
		
		while (!error && keep_going)
		{
			char* label = NULL;
			size_t size;
			char* value = NULL;
			
			if (t->token == t_string)
			{
				error = 0
					?: read_token(t)
					?: (t->token != t_label ? e_syntax_error : 0)
					?: tstrdup(&label, t->data.label.text)
					?: read_token(t)
					?: (t->token != t_comma ? e_syntax_error : 0)
					?: read_token(t)
					?: (t->token != t_string_literal ? e_syntax_error : 0)
					?: tstrndup(&value, t->data.string.chars, size = t->data.string.len)
					?: scope_declare_global(scope, label, size, value)
					?: read_token(t)
					 ;
			}
			else if (t->token == t_float)
			{
				TODO;
			}
			else if (t->token == t_global)
			{
				TODO;
			}
			else
				keep_going = false;
			
			tfree(label), tfree(value);
		}
	}
	
	EXIT;
	return error;
}



















