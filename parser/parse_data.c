
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

#include <macros/streq.h>

#include <memory/tstrdup.h>
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
			
			if (t->token == t_string)
			{
				// use malloc not mmap
				TODO;
				#if 0
				error = read_token(t);
				
				if (!error && t->token != t_label)
				{
					TODO;
					error = 1;
				}
				
				if (!error)
					error = tstrdup(&label, t->data.label.text);
				
				if (!error)
					error = read_token(t);
				
				if (!error && t->token != t_comma)
				{
					TODO;
					error = 1;
				}
				
				if (!error)
					error = read_token(t);
				
				if (!error && t->token != t_string_literal)
				{
					TODO;
					error = 1;
				}
				
				if (!error)
				{
					size_t n = t->data.string.len + 1;
					
					globals -= n;
					
					memcpy(globals, t->data.string.chars, n);
					
					dpvs(globals);
					
					assert(scope);
					
					error = scope_declare_global(scope, label, globals);
				}
				
				if (!error)
					error = read_token(t);
				#endif
				
			}
			else if (t->token == t_float)
			{
				// use malloc not mmap
				TODO;
				#if 0
				error = read_token(t);
				
				if (!error && t->token != t_label)
				{
					TODO;
					error = 1;
				}
				
				if (!error)
					error = tstrdup(&label, t->data.label.text);
				
				if (!error)
					error = read_token(t);
				
				if (!error && t->token != t_comma)
				{
					TODO;
					error = 1;
				}
				
				if (!error)
					error = read_token(t);
				
				if (!error && t->token != t_float_literal)
				{
					TODO;
					error = 1;
				}
				
				if (!error)
				{
					dpv(t->data.floatlit.value);
					
					globals -= sizeof(float);
					
					memcpy(globals, &t->data.floatlit.value, sizeof(float));
					
					dpv(globals);
					dpv(*((float*) globals));
					
					error = scope_declare_global(scope, label, globals);
				}
				
				if (!error)
					error = read_token(t);
				#endif
				
			}
			else if (t->token == t_global)
			{
				// use malloc not mmap
				TODO;
				#if 0
				size_t size, align;
				
				error = read_token(t);
				
				if (!error && t->token != t_label)
				{
					TODO;
					error = 1;
				}
				
				if (!error)
					error = tstrdup(&label, t->data.label.text);
				
				if (!error)
					error = read_token(t);
				
				if (!error && t->token != t_comma)
				{
					TODO;
					error = 1;
				}
				
				if (!error)
					error = read_token(t);
				
				if (!error && t->token != t_integer_literal)
				{
					TODO;
					error = 1;
				}
				
				if (!error)
				{
					size = t->data.intlit.value;
					error = read_token(t);
				}
				
				if (!error && t->token != t_comma)
				{
					TODO;
					error = 1;
				}
				
				if (!error)
					error = read_token(t);
				
				if (!error && t->token != t_integer_literal)
				{
					TODO;
					error = 1;
				}
				
				if (!error)
				{
					align = t->data.intlit.value;
					dpv(size);
					dpv(align);
					
					globals -= size;
					globals -= align - (intptr_t) globals % align;
					error = scope_declare_global(scope, label, globals);
				}
				
				if (!error)
					error = read_token(t);
				#endif
				
			}
			else
			{
				keep_going = false;
			}
			
			tfree(label);
		}
	}
	
	EXIT;
	return error;
}



















