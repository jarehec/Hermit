#include "util.h"

/**
* malloc_checked - allocates memory
* @b: number of bytes
* Return: pointer to allocated memory
*/
void *malloc_checked(unsigned int b)
{
	void *mem = malloc(b);

	if (!mem)
	{
		fputs("Ran out of memory", stderr);
		exit(-1);
	}
	return (mem);
}
