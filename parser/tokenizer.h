
#include <stdio.h>

struct tokenizer
{
	FILE* in;
	
	unsigned line, column;
	unsigned token_line, token_column;
	
	struct {
		char* data;
		size_t n, cap;
	} text;
	
	enum {
		t_EOF,
		
		// symbols:
		t_colon,
		t_comma,
		t_arrow,
		
		// tokens:
		t_label,
		t_vregister,
		
		// literals:
		t_float_literal,
		t_string_literal,
		t_integer_literal,
		
		// pesudo-ops:
		t_data,
		t_string,
		t_float,
		t_global,
		t_text,
		t_frame,
		
		// Integer Arthmetic Instructions
		t_i2i,
		t_add,
		t_sub,
		t_mult,
		t_lshift,
		t_rshift,
		t_mod,
		t_and,
		t_or,
		t_not,
		t_addI,
		t_subI,
		t_multI,
		t_lshiftI,
		t_rshiftI,
		
		// Integer Memory Operations:
		t_loadI,
		t_load,
		t_loadAI,
		t_loadAO,
		t_store,
		t_storeAI,
		t_storeAO,
		
		// Compare Instructions:
		t_cmp_LT,
		t_cmp_LE,
		t_cmp_GT,
		t_cmp_GE,
		t_cmp_EQ,
		t_cmp_NE,
		t_comp,
		t_testeq,
		t_testne,
		t_testgt,
		t_testge,
		t_testlt,
		t_testle,
		
		// Floating-point Operations
		t_f2i,
		t_i2f,
		t_f2f,
		t_fadd,
		t_fsub,
		t_fmult,
		t_fdiv,
		t_fcomp,
		t_fload,
		t_floadAI,
		t_floadAO,
		t_fstore,
		t_fstoreAI,
		t_fstoreAO,
		
		// I/O Instructions:
		t_fread,
		t_iread,
		t_fwrite,
		t_iwrite,
		t_swrite,
		
		// Branch Instructions:
		t_jumpI,
		t_jump,
		t_ret,
		t_cbr,
		t_cbrne,
		t_cbr_LT,
		t_cbr_LE,
		t_cbr_GT,
		t_cbr_GE,
		t_cbr_EQ,
		t_cbr_NE,
		
		// Undocumented Instructions
		t_nop,
	} token;
	
	union {
		struct {
			char* text;
		} label;
		
		struct {
			unsigned index;
		} vregister;
		
		struct {
			double value;
		} floatlit;
		struct {
			char* chars;
			size_t len;
		} string;
		struct {
			int32_t value;
		} intlit;
	} data;
	
	unsigned max_vreg;
};
















