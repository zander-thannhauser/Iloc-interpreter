
struct avl_tree_t;

struct scope
{
	struct avl_tree_t* globals;
	
	struct avl_tree_t* blocks;
	
	struct avl_tree_t* unresolved;
};

