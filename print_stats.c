
#include <stdio.h>
#include <locale.h>

#include <structs/stats.h>

#include "print_stats.h"

void print_stats(struct stats* this)
{
	ENTER;
	
	// setlocale(LC_ALL, "");
	
	if (this->adds)        printf("%12s: %'5u\n", "adds",        this->adds);
	if (this->subtracts)   printf("%12s: %'5u\n", "subtracts",   this->subtracts);
	if (this->multiplys)   printf("%12s: %'5u\n", "multiplys",   this->multiplys);
	if (this->divides)     printf("%12s: %'5u\n", "divides",     this->divides);
	
	if (this->comparisons) printf("%12s: %'5u\n", "comparisons", this->comparisons);
	
	if (this->stores)      printf("%12s: %'5u\n", "stores",      this->stores);
	if (this->loads)       printf("%12s: %'5u\n", "loads",       this->loads);
	
	if (this->total)       printf("%12s: %'5u\n", "total",       this->total);
	
	EXIT;
}

