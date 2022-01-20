
struct vregister
{
	#ifdef ASM_VERBOSE
	enum {
		vk_int,
		vk_ptr,
		vk_flt,
	} kind;
	#endif
	
	union
	{
		int    as_int;
		float  as_float;
		
		void*  as_ptr;
		void** as_pptr;
		int*   as_iptr;
		float* as_fptr;
		char*  as_cptr;
	};
};

