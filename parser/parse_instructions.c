
#include <assert.h>
#include <stdbool.h>

#include <enums/error.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <scope/lookup_block.h>
#include <scope/lookup_global.h>

#include <instruction/struct.h>

// Integer Arthmetic Instructions:
#include <instruction/i2i/new.h>
#include <instruction/add/new.h>
#include <instruction/sub/new.h>
#include <instruction/mult/new.h>
#include <instruction/mod/new.h>
#include <instruction/or/new.h>

// Integer Memory Operations:
#include <instruction/loadI/new.h>
#include <instruction/load/new.h>
#include <instruction/store/new.h>

// Compare Instructions
#include <instruction/comp/new.h>
#include <instruction/testeq/new.h>
#include <instruction/testgt/new.h>
#include <instruction/testlt/new.h>
#include <instruction/testle/new.h>
#include <instruction/testne/new.h>
#include <instruction/testge/new.h>

// Floating-point Instructions:
#include <instruction/f2i/new.h>
#include <instruction/i2f/new.h>
#include <instruction/fadd/new.h>
#include <instruction/fmult/new.h>
#include <instruction/fload/new.h>

// I/O Instructions:
#include <instruction/iread/new.h>
#include <instruction/iwrite/new.h>
#include <instruction/swrite/new.h>

// Branch Instructions
#include <instruction/jumpI/new.h>
#include <instruction/ret/new.h>
#include <instruction/cbr/new.h>
#include <instruction/cbrne/new.h>

// Undocumented Instructions:
#include <instruction/nop/new.h>
#include <instruction/call/new.h>
#include <instruction/iret/new.h>
#include <instruction/icall_master/new.h>
#include <instruction/icall_slave/new.h>

#include <misc/vregister_ll/struct.h>
#include <misc/vregister_ll/new.h>
#include <misc/vregister_ll/append.h>

#include "tokenizer.h"
#include "read_token.h"
#include "parse_instructions.h"

int parse_instructions(
	struct tokenizer* t,
	struct scope* s,
	size_t* out_nparameters,
	struct instruction** next)
{
	int error = 0;
	bool keep_going = true;
	int intlit;
	bool isint;
	unsigned vr1, vr2, vr3;
	ENTER;
	
	dpv(*next);
	
	#define T ?: read_token(t)
	
	#define S error = 0 T
	
	#define E(error) ?: (t->token != (error) ? e_syntax_error : 0)
	#define II       ?: (intlit = t->data.intlit.value, 0)
	#define RR(i)    ?: (vr##i = t->data.intlit.value, 0)
	#define LL       ?: scope_lookup_block(s, t->data.label.text, &label)
	#define GG       ?: scope_lookup_global(s, t->data.label.text, (void**) &intlit)
	
	#define I        E(t_integer_literal) II T
	#define R(i)     E(t_vregister) RR(i) T
	#define A        E(t_arrow) T
	#define C        E(t_comma) T
	#define L        E(t_label) LL T
	#define G        E(t_label) GG T
	
	#define IorG     ?: ((isint = t->token == t_integer_literal) ? (0 II) : (0 GG)) T
	
	#define N(name, ...) ?: new_##name##_instruction(&current, line __VA_OPT__(,) __VA_ARGS__)
	
	while (!error && keep_going)
	{
		struct instruction* current = NULL;
		struct instruction* label = NULL;
		struct vregister_ll* regs = NULL;
		
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
			case t_mod:     S R(1) C R(2) A R(3) N(mod, vr1, vr2, vr3); break;
			case t_and:     TODO; break;
			case t_or:      S R(1) C R(2) A R(3) N(or, vr1, vr2, vr3); break;
			case t_not:     TODO; break;
			case t_addI:    TODO; break;
			case t_subI:    TODO; break;
			case t_multI:   TODO; break;
			case t_lshiftI: TODO; break;
			case t_rshiftI: TODO; break;
			
			// Integer Memory Operations
			case t_loadI:   S IorG A R(1) N(loadI, intlit, isint, vr1); break;
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
			case t_testeq: S R(1)        A R(3) N(testeq, vr1,      vr3); break;
			case t_testne: S R(1)        A R(3) N(testne, vr1,      vr3); break;
			case t_testgt: S R(1)        A R(3) N(testgt, vr1,      vr3); break;
			case t_testge: S R(1)        A R(3) N(testge, vr1,      vr3); break;
			case t_testlt: S R(1)        A R(3) N(testlt, vr1,      vr3); break;
			case t_testle: S R(1)        A R(3) N(testle, vr1,      vr3); break;
			
			// Floating-point Operations
			case t_f2i:      S R(1) A R(3) N(f2i, vr1, vr3); break;
			case t_i2f:      S R(1) A R(3) N(i2f, vr1, vr3); break;
			case t_f2f:      TODO; break;
			case t_fadd:     S R(1) C R(2) A R(3) N(fadd, vr1, vr2, vr3); break;
			case t_fsub:     TODO; break;
			case t_fmult:    S R(1) C R(2) A R(3) N(fmult, vr1, vr2, vr3); break;
			case t_fdiv:     TODO; break;
			case t_fcomp:    TODO; break;
			case t_fload:    S R(1) A R(3) N(fload,  vr1, vr3); break;
			case t_floadAI:  TODO; break;
			case t_floadAO:  TODO; break;
			case t_fstore:   TODO; break;
			case t_fstoreAI: TODO; break;
			case t_fstoreAO: TODO; break;
			
			// I/O Instructions:
			case t_fread:  TODO; break;
			case t_iread:  S R(1) N(iread, vr1); break;
			case t_fwrite: TODO; break;
			case t_iwrite: S R(1) N(iwrite, vr1); break;
			case t_swrite: S R(1) N(swrite, vr1); break;
			
			// Branch Instructions:
			case t_jumpI:  S A L N(jumpI, label); break;
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
			
			case t_call:
			{
				S L ?: new_vregister_ll(&regs);
				
				while (!error && t->token == t_comma)
					S R(1) ?: vregister_ll_append(regs, vr1);
				
				if (!error)
				{
					if (regs->n > *out_nparameters)
						*out_nparameters = regs->n;
					
					error = new_call_instruction(&current, line, label, regs);
				}
				break;
			}
			
			case t_icall:
			{
				struct instruction* master = NULL;
				
				S L ?: new_vregister_ll(&regs);
				
				while (!error && t->token == t_comma)
					S R(1) ?: vregister_ll_append(regs, vr1);
				
				if (!error)
				{
					if (regs->n > *out_nparameters)
						*out_nparameters = regs->n;
					
					error = 0 A R(3);
				}
				
				if (!error)
					error = 0
						?: new_icall_master_instruction(&master, line, label, regs, vr3)
						?: new_icall_slave_instruction(&current, vr3);
				
				if (!error)
				{
					// guarantee space for the return value:
					if (1 > *out_nparameters)
						*out_nparameters = 1;
						
					(*next)->next = tinc(master);
					(*next) = master;
				}
				
				tfree(master);
				break;
			}
			
			case t_iret: S R(1) N(iret, vr1); break;
			
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
		
		tfree(regs);
		tfree(label);
		tfree(current);
	}
	
	EXIT;
	return error;
}



















