#include "main.h"

/**
 * print_s - returns string
 * @list: string
 * Return: string
 */

char *print_s(va_list list)
{	
	char *string;
	char *p;
	int len;

	string = va_arg(list, char *);
	if (string == NULL)
		string = "(null)";

	len = _strlen(string);
	p = malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);

	return (_strcpy(p, string));
}	
