#include "main.h"



/**
  * _realloc - reallocates a memory block
  * @ptr: ptr to memory block
  * @old_size: size in byte of block of mem
  * @new_size: size in byte of new mem
  * description: reallocaates a memory block
  * Return: pointer to new memory location
*/


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned char *mem;

	if ((old_size > new_size) && (ptr != NULL && new_size > 0))
	{
		mem = malloc(new_size);
		if (mem == NULL)
			return (NULL);
		_memcpy(mem, ptr, new_size);
	}
	else if ((old_size < new_size) && (ptr != NULL && new_size > 0))
	{
		mem = malloc(new_size);
		if (mem == NULL)
			return (NULL);
		_memcpy(mem, ptr, old_size);
	}
	else if (old_size == new_size)
	{
		return (ptr);
	}
	else if (ptr == NULL)
	{
		mem = malloc(new_size);
		if (mem == NULL)
			return (NULL);
	}
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		return (NULL);
	}
	free(ptr);
	return (mem);
}

/**
  * _memcpy - copies mem block
  * @dest: ptr to memory block
  * @src: source mem location
  * @n: number of bytes to copy
  * description: reallocaates a memory block
  * Return: pointer to new memory location
*/

void *_memcpy(void *dest, void *src, size_t n)
{
	unsigned char *dest_cpy, *src_cpy;
	size_t i;

	if (dest == NULL || src == NULL)
		return (NULL);
	dest_cpy = dest;
	src_cpy = src;
	for (i = 0; i < n; i++)
	{
		dest_cpy[i] = src_cpy[i];
	}
	return (dest);
}
