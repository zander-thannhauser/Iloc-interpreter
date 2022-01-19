
#include <sys/param.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

#include <defines/argv0.h>

#include <enums/error.h>

#include <memory/trealloc.h>

#include "tokenizer.h"
#include "read_token.h"

static const enum state {
	s_error,
	
	s_EOF,
	
	// symbols:
	s_colon,
	s_comma,
	s_arrow,
	
	s_keyword,
	s_vregister,
	
	// literals:
	s_integer,
	s_float,
	s_string,
	
	s_start,
	
	s_after_colon,
	s_after_comma,
	s_after_equals,
	s_after_arrow,
	s_after_minus,
	
	s_reading_comment,
	s_reading_keyword,
	
	s_reading_register_0,
	s_reading_register_1,
	s_reading_register_2,
	s_reading_register_3,
	
	s_reading_string,
	s_reading_string_escape,
	s_reading_string_escape_octal,
	s_after_string,
	
	s_reading_integer,
	s_reading_float,
	
	number_of_states,
} lookup[number_of_states][128] = {
	#define ALL 0 ... 127
	
	// EOF
	[s_start][0] = s_EOF,
	
	// whitespace:
	[s_start][' ' ] = s_start,
	[s_start]['\t'] = s_start,
	[s_start]['\n'] = s_start,
	
	// symbols:
	[s_start][':'] = s_after_colon,
		[s_after_colon][ALL] = s_colon,
	[s_start][','] = s_after_comma,
		[s_after_comma][ALL] = s_comma,
	[s_start]['='] = s_after_equals,
		[s_after_equals]['>'] = s_after_arrow,
			[s_after_arrow][ALL] = s_arrow,
	[s_start]['-'] = s_after_minus,
		[s_after_minus]['>'] = s_after_arrow,
			[s_after_arrow][ALL] = s_arrow,
	
	// '#'-comments:
	[s_start]['#'] = s_reading_comment,
		[s_reading_comment][ALL] = s_reading_comment,
		[s_reading_comment]['\n'] = s_start,
	
	// keywords:
	[s_start]['.'] = s_reading_keyword,
	[s_start]['a' ... 'z'] = s_reading_keyword,
		[s_reading_keyword][ALL] = s_keyword,
		[s_reading_keyword]['0' ... '9'] = s_reading_keyword,
		[s_reading_keyword]['a' ... 'z'] = s_reading_keyword,
		[s_reading_keyword]['A' ... 'Z'] = s_reading_keyword,
		[s_reading_keyword]['_'] = s_reading_keyword,
	
	// virtual registers:
	[s_start]['%'] = s_reading_register_0,
		[s_reading_register_0]['v'] = s_reading_register_1,
		[s_reading_register_1]['r'] = s_reading_register_2,
		[s_reading_register_2]['0' ... '9'] = s_reading_register_3,
		[s_reading_register_3][    ALL    ] = s_vregister,
		[s_reading_register_3]['0' ... '9'] = s_reading_register_3,
	
	// integer/float literal:
	[s_start]['0' ... '9'] = s_reading_integer,
		[s_after_minus]['0' ... '9'] = s_reading_integer,
		
		[s_reading_integer][    ALL    ] = s_integer,
		[s_reading_integer]['0' ... '9'] = s_reading_integer,
		[s_reading_integer][    '.'    ] = s_reading_float,
		[s_reading_float  ][    ALL    ] = s_float,
		[s_reading_float  ]['0' ... '9'] = s_reading_float,
	
	// string literal:
	[s_start]['\"'] = s_reading_string,
		[s_reading_string][ALL] = s_reading_string,
		[s_reading_string]['\\'] = s_reading_string_escape,
			[s_reading_string_escape]['n'] = s_reading_string_escape,
			[s_reading_string_escape]['t'] = s_reading_string_escape,
			[s_reading_string_escape]['\\'] = s_reading_string_escape,
			[s_reading_string_escape]['\"'] = s_reading_string_escape,
			[s_reading_string_escape]['0' ... '9'] = s_reading_string_escape_octal,
				[s_reading_string_escape_octal][ALL] = s_reading_string,
				[s_reading_string_escape_octal]['\"'] = s_after_string,
				[s_reading_string_escape_octal]['0' ... '9'] = s_reading_string_escape_octal,
		[s_reading_string]['\"'] = s_after_string,
		[s_after_string][ALL] = s_string,
};

int read_token(struct tokenizer* this)
{
	int error = 0;
	enum state state = s_start;
	ENTER;
	
	int append(char c)
	{
		int error = 0;
		
		if (this->text.n + 1 >= this->text.cap)
			this->text.cap = this->text.cap * 2 ?: 1,
			error = trealloc((void**) &this->text.data, this->text.cap);
		
		if (!error)
			this->text.data[this->text.n++] = c;
		
		return error;
	}
	
	dpv(this->line);
	
	char c = getc(this->in);
	dpvc(c);
	
	unsigned token_line;
	goto start;
	while (!error && state >= s_start)
	{
		this->line += c == '\n';
		
		error = append(c);
		
		c = getc(this->in);
		
		if (state == s_start)
		{
			start:
			this->text.n = 0;
			token_line = this->line;
		}
		
		state = lookup[state][MAX(c, 0)];
	}
	
	ungetc(c, this->in);
	
	this->token_line = token_line;
	
	dpv(state);
	dpvsn(this->text.data, this->text.n);
	dpv(token_line);
	
	switch (state)
	{
		case s_error:
		{
			fprintf(stderr, "%s: line %u: unknown token '%.*s%c'!\n", argv0,
				token_line,
				(int) this->text.n, this->text.data, c);
			error = e_lexical_error;
			break;
		}
		
		case s_EOF:
		{
			this->token = t_EOF;
			break;
		}
		
		// symbols:
		case s_colon:
			this->token = t_colon;
			break;
		
		case s_comma:
			this->token = t_comma;
			break;
		
		case s_arrow:
			this->token = t_arrow;
			break;
		
		case s_keyword:
		{
			ddprintf("s_keyword" "\n");
			
			#define matches(str) \
				(this->text.n == strlen(str) && !strncmp(this->text.data, str, this->text.n))
			
			#define O(instruction) \
				if (matches("." #instruction)) this->token = t_##instruction
				
			#define T(instruction) \
				if (matches(#instruction)) this->token = t_##instruction
			
			// psudo-ops:
			O (data);
			else O (string);
			else O (float);
			else O (global);
			else O (text);
			else O (frame);
			// Integer Arthmetic Instructions:
			else T(i2i);
			else T(add);
			else T(sub);
			else T(mult);
			else T(lshift);
			else T(rshift);
			else T(mod);
			else T(and);
			else T(or);
			else T(not);
			else T(addI);
			else T(subI);
			else T(multI);
			else T(lshiftI);
			else T(rshiftI);
			// Integer Memory Operations:
			else T(loadI);
			else T(load);
			else T(loadAI);
			else T(loadAO);
			else T(store);
			else T(storeAI);
			else T(storeAO);
			// Compare Instructions:
			else T(cmp_LT);
			else T(cmp_LE);
			else T(cmp_GT);
			else T(cmp_GE);
			else T(cmp_EQ);
			else T(cmp_NE);
			else T(comp);
			else T(testeq);
			else T(testne);
			else T(testgt);
			else T(testge);
			else T(testlt);
			else T(testle);
			// Floating-point Instructions:
			else T(f2i);
			else T(i2f);
			else T(f2f);
			else T(fadd);
			else T(fsub);
			else T(fmult);
			else T(fdiv);
			else T(fcomp);
			else T(fload);
			else T(floadAI);
			else T(floadAO);
			else T(fstore);
			else T(fstoreAI);
			else T(fstoreAO);
			// I/O Instructions:
			else T(fread);
			else T(iread);
			else T(fwrite);
			else T(iwrite);
			else T(swrite);
			// Branch Instructions:
			else T(jumpI);
			else T(jump);
			else T(ret);
			else T(cbr);
			else T(cbrne);
			else T(cbr_LT);
			else T(cbr_LE);
			else T(cbr_GT);
			else T(cbr_GE);
			else T(cbr_EQ);
			else T(cbr_NE);
			// Undocumented Instructions:
			else T(nop);
			else T(call);
			else
			{
				append('\0');
				
				this->data.label.text = this->text.data;
				
				dpvs(this->data.label.text);
				
				this->token = t_label;
			}
			break;
		}
		
		case s_vregister:
		{
			char* m;
			
			ddprintf("s_vregister" "\n");
			
			append('\0');
			
			errno = 0;
			
			unsigned index = strtoul(this->text.data + 3, &m, 10);
			
			assert(!errno && !*m); // the state machine guarantees a valid int
			
			dpv(index);
			
			if (index > this->max_vreg)
				this->max_vreg = index;
			
			this->token = t_vregister;
			this->data.vregister.index = index;
			
			break;
		}
		
		char* m;
		
		// literals:
		case s_integer:
		{
			ddprintf("s_integer" "\n");
			
			append('\0');
			
			errno = 0;
			signed long value = strtol(this->text.data, &m, 0);
			
			if (errno || *m || value > INT32_MAX || value < INT32_MIN)
			{
				TODO;
				error = 1;
			}
			else
			{
				dpv(value);
				
				this->data.intlit.value = value;
				this->token = t_integer_literal;
			}
			break;
		}
		
		case s_float:
		{
			ddprintf("s_float" "\n");
			append('\0');
			
			errno = 0;
			float value = strtof(this->text.data, &m);
			
			if (errno || *m)
			{
				TODO;
				error = 1;
			}
			else
			{
				dpv(value);
				
				this->data.floatlit.value = value;
				this->token = t_float_literal;
			}
			break;
		}
		
		case s_string:
		{
			ddprintf("s_string" "\n");
			
			char *s = this->text.data, *e = s + this->text.n - 1,
				*w = s, *r = w + 1;
			
			for (; r < e; w++)
				if (*r != '\\')
					*w = *r++;
				else switch (*++r) {
					case 't': *w = '\t', r++; break;
					
					case '0' ... '7':
					*w = 0; do
						*w = (*w << 3) | (*r++ - '0');
					while ('0' <= *r && *r <= '7');
					break;
					
					default:
						TODO;
						break;
				}
			
			*w = '\0';
			
			this->data.string.chars = this->text.data;
			this->data.string.len = w - s;
			
			dpvsn(this->data.string.chars, w - s);
			
			this->token = t_string_literal;
			break;
		}
		
		default:
			TODO;
			break;
	}
	
	EXIT;
	return error;
}













