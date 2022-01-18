
#include <assert.h>
#include <stdbool.h>

#include <enums/error.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <scope/lookup_block.h>

#include <instruction/struct.h>

// Integer Arthmetic Instructions:
#include <instruction/i2i/new.h>
#include <instruction/add/new.h>
#include <instruction/sub/new.h>
#include <instruction/mult/new.h>

// Integer Memory Operations:
#include <instruction/loadI/new.h>
#include <instruction/load/new.h>
#include <instruction/store/new.h>

// Compare Instructions
#include <instruction/comp/new.h>
#include <instruction/testgt/new.h>
#include <instruction/testlt/new.h>
#include <instruction/testle/new.h>

// Floating-point Instructions:

// I/O Instructions:
#include <instruction/iwrite/new.h>

// Branch Instructions
#include <instruction/ret/new.h>
#include <instruction/cbr/new.h>
#include <instruction/cbrne/new.h>

// Undocumented Instructions:
#include <instruction/nop/new.h>

#include "tokenizer.h"
#include "read_token.h"
#include "parse_instructions.h"

int parse_instructions(
	struct tokenizer* t,
	struct scope* s,
	struct instruction** next)
{
	int error = 0;
	bool keep_going = true;
	signed int intlit;
	unsigned vr1, vr2, vr3;
	ENTER;
	
	dpv(*next);
	
	#define T ?: read_token(t)
	
	#define S error = 0 T
	
	#define E(error) ?: (t->token != (error) ? e_syntax_error : 0)
	#define II       ?: (intlit = t->data.intlit.value, 0)
	#define RR(i)    ?: (vr##i = t->data.intlit.value, 0)
	#define LL       ?: scope_lookup_block(s, t->data.label.text, &label)
	
	#define I        E(t_integer_literal) II T
	#define R(i)     E(t_vregister) RR(i) T
	#define A        E(t_arrow) T
	#define C        E(t_comma) T
	#define L        E(t_label) LL T
	
	#define N(name, ...) ?: new_##name##_instruction(&current, line __VA_OPT__(,) __VA_ARGS__)
	
	while (!error && keep_going)
	{
		struct instruction* current = NULL;
		struct instruction* label = NULL;
		
		unsigned line = t->token_line;
		
		dpv(line);
		
		switch (t->token)
		{
			// Integer Arthmetic Instructions:
			case t_i2i:     S R(1)        A R(3) N(i2i,  vr1,      vr3); break;
			case t_add:     S R(1) C R(2) A R(3) N(add,  vr1, vr2, vr3); break;
			case t_sub:     S R(1) C R(2) A R(3) N(sub,  vr1, vr2, vr3); break;
			case t_mult:    S R(1) C R(2) A R(3) N(mult, vr1, vr2, vr3); break;
			case t_lshift:  TODO; break;
			case t_rshift:  TODO; break;
			case t_mod:     TODO; break;
			case t_and:     TODO; break;
			case t_or:      TODO; break;
			case t_not:     TODO; break;
			case t_addI:    TODO; break;
			case t_subI:    TODO; break;
			case t_multI:   TODO; break;
			case t_lshiftI: TODO; break;
			case t_rshiftI: TODO; break;
			
			// Integer Memory Operations
			case t_loadI:   S I    A R(1) N(loadI, intlit, vr1); break;
			case t_load:    S R(1) A R(3) N(load,  vr1, vr3); break;
			case t_loadAI:  TODO; break;
			case t_loadAO:  TODO; break;
			case t_store:   S R(1) A R(3) N(store, vr1, vr3); break;
			case t_storeAI: TODO; break;
			case t_storeAO: TODO; break;
			
			// Compare Instructions
			case t_cmp_LT: TODO; break;
			case t_cmp_LE: TODO; break;
			case t_cmp_GT: TODO; break;
			case t_cmp_GE: TODO; break;
			case t_cmp_EQ: TODO; break;
			case t_cmp_NE: TODO; break;
			case t_comp:   S R(1) C R(2) A R(3) N(comp,   vr1, vr2, vr3); break;
			case t_testeq: TODO; break;
			case t_testne: TODO; break;
			case t_testgt: S R(1)        A R(3) N(testgt, vr1,      vr3); break;
			case t_testge: TODO; break;
			case t_testlt: S R(1)        A R(3) N(testlt, vr1,      vr3); break;
			case t_testle: S R(1)        A R(3) N(testle, vr1,      vr3); break;
			
			// Floating-point Operations
			case t_f2i:      TODO; break;
			case t_i2f:      TODO; break;
			case t_f2f:      TODO; break;
			case t_fadd:     TODO; break;
			case t_fsub:     TODO; break;
			case t_fmult:    TODO; break;
			case t_fdiv:     TODO; break;
			case t_fcomp:    TODO; break;
			case t_fload:    TODO; break;
			case t_floadAI:  TODO; break;
			case t_floadAO:  TODO; break;
			case t_fstore:   TODO; break;
			case t_fstoreAI: TODO; break;
			case t_fstoreAO: TODO; break;
			
			// I/O Instructions:
			case t_fread:  TODO; break;
			case t_iread:  TODO; break;
			case t_fwrite: TODO; break;
			case t_iwrite: S R(1) N(iwrite, vr1); break;
			case t_swrite: TODO; break;
			
			// Branch Instructions:
			case t_jumpI:  TODO; break;
			case t_jump:   TODO; break;
			case t_ret:    S          N(ret); break;
			case t_cbr:    S R(1) A L N(cbr,   vr1, label); break;
			case t_cbrne:  S R(1) A L N(cbrne, vr1, label); break;
			case t_cbr_LT: TODO; break;
			case t_cbr_LE: TODO; break;
			case t_cbr_GT: TODO; break;
			case t_cbr_GE: TODO; break;
			case t_cbr_EQ: TODO; break;
			case t_cbr_NE: TODO; break;
			
			// Undocumented Instructions:
			case t_nop:    S N(nop); break;
			
			default:
				keep_going = false;
				break;
		}
		
		if (!error && keep_going)
		{
			dpv(*next);
			
			(*next)->next = tinc(current);
			(*next) = current;
		}
		
		tfree(label);
		tfree(current);
	}
	
	EXIT;
	return error;
}



















