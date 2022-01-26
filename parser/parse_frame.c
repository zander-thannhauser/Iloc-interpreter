
#include <assert.h>

#include <enums/error.h>

#include <memory/tstrdup.h>
#include <memory/tfree.h>

#include <scope/declare_block.h>

#include <instruction/struct.h>
#include <instruction/frame/struct.h>
#include <instruction/frame/new.h>

#include <misc/vregister_ll/struct.h>
#include <misc/vregister_ll/new.h>
#include <misc/vregister_ll/append.h>

#include "tokenizer.h"
#include "read_token.h"

#include "parse_instructions.h"
#include "parse_frame.h"

int parse_frame(
	struct tokenizer* t,
	struct scope* s,
	size_t* out_nps)
{
	int error = 0;
	char* funcname = NULL;
	unsigned frame_size;
	struct vregister_ll* args = NULL;
	struct instruction* frame = NULL, *next;
	ENTER;
	
	assert(t->token == t_frame);
	
	unsigned line = t->token_line;
	
	t->max_vreg = 4;
	
	error = 0
		?: read_token(t)
		?: (t->token != t_label ? e_syntax_error : 0)
		?: tstrdup(&funcname, t->data.label.text)
		?: read_token(t)
		?: (t->token != t_comma ? e_syntax_error : 0)
		?: read_token(t)
		?: (t->token != t_integer_literal || t->data.intlit.value < 0 ? e_syntax_error : 0)
		?: (frame_size = t->data.intlit.value, read_token(t))
		?: new_vregister_ll(&args);
		 ;
	
	unsigned vr;
	while (!error && t->token == t_comma)
	{
		error = 0
			?: read_token(t)
			?: (t->token != t_vregister ? e_syntax_error : 0)
			?: (vr = t->data.vregister.index, read_token(t))
			?: vregister_ll_append(args, vr);
	}
	
	if (!error)
	{
		if (args->n > *out_nps)
			*out_nps = args->n;
		
		error = 0
			?: new_frame_instruction(&frame, line, funcname, frame_size, args)
			?: scope_declare_block(s, funcname, frame)
			?: (next = frame, parse_instructions(t, s, out_nps, &next))
			 ;
	}
	
	while (!error
		&& t->token == t_label
		&& t->data.label.text[0] == '.')
	{
		char* label = NULL;
		struct instruction* old_next = next;
		
		error = 0
			?: tstrdup(&label, t->data.label.text)
			?: read_token(t)
			?: (t->token == t_colon ? 0 : e_syntax_error)
			?: read_token(t)
			?: parse_instructions(t, s, out_nps, &next)
			?: scope_declare_block(s, label, old_next->next)
			 ;
		
		tfree(label);
	}
	
	((struct frame_instruction*) frame)->nregs = t->max_vreg + 1;
	
	tfree(frame);
	tfree(funcname);
	
	EXIT;
	return error;
}































