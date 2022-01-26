
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

#include <macros/streq.h>

#include <enums/error.h>

#include <memory/tstrdup.h>
#include <memory/tmemdup.h>
#include <memory/tcalloc.h>
#include <memory/tfree.h>

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
			void* value = NULL;
			
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
					?: tmemdup((void**) &value,
						t->data.string.chars, t->data.string.len)
					?: read_token(t)
					 ;
			}
			else if (t->token == t_float)
			{
				error = 0
					?: read_token(t)
					?: (t->token != t_label ? e_syntax_error : 0)
					?: tstrdup(&label, t->data.label.text)
					?: read_token(t)
					?: (t->token != t_comma ? e_syntax_error : 0)
					?: read_token(t)
					?: (t->token != t_float_literal ? e_syntax_error : 0)
					?: tmemdup((void**) &value, &t->data.floatlit.value, sizeof(float))
					?: read_token(t)
					 ;
			}
			else if (t->token == t_global)
			{
				error = 0
					?: read_token(t)
					?: (t->token != t_label ? e_syntax_error : 0)
					?: tstrdup(&label, t->data.label.text)
					?: read_token(t)
					?: (t->token != t_comma ? e_syntax_error : 0)
					?: read_token(t)
					?: (t->token != t_integer_literal ? e_syntax_error : 0)
					?: tcalloc((void**) &value, t->data.intlit.value, 1)
					?: read_token(t)
					?: (t->token != t_comma ? e_syntax_error : 0)
					?: read_token(t)
					?: (t->token != t_integer_literal ? e_syntax_error : 0)
					?: read_token(t)
					 ;
			}
			else
			{
				keep_going = false;
			}
			
			if (!error && keep_going)
				error = scope_declare_global(scope, label, value);
			
			tfree(label);
			tfree(value);
		}
	}
	
	EXIT;
	return error;
}



















