
struct vregister_ll;

void vregister_ll_foreach(
	struct vregister_ll* this,
	void (*callme)(unsigned));
