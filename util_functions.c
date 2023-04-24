#include "main.h"
#include <stdio.h>

/**
 * get_func - returns required function
 * @i: function identifier
 * Return: pointer to required function
 */
int p;

char* (*get_function(char i))(va_list)
{
	int z = 0;

	print keys[] = {
		{'c', print_c},
		{'s', print_s}
	};

	while (keys[z].id == i)
	{
		if (keys[z].id == i)
			return (keys[z].func);
		z++;
	}
	return (NULL);
}

/**
 * create_buffer - create buffer to hold string before printing
 * Return: pointer to buffer created
 */

char *create_buffer(void)
{
	char *buffer;
	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

/**
 * write_buffer - prints buffer, frees buffer & va_list
 * @buffer: buffer
 * @len: lenth of string to be printed.
 * @list: va_list
 */
 
void write_buffer(char *buffer, int len, va_list list)
{
	char *b;

	b = realloc(buffer, len);
	write(1, b, len);
	free(b); va_end(list);
}	
