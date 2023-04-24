#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* utility functions */
char* (*get_function(char i))(va_list);
char *create_buffer(void);
void write_buffer(char *buffer, int len, va_list list);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);


int _printf(const char *format, ...);
char *print_c(va_list list);
char *print_s(va_list list);


/**
 * struct types - struct
 * @id: identifier of type to print
 * @func: ptr to printing function according to identifier
 */

typedef struct types
{
	char id;
	char* (*func)(va_list);
}print;

#endif
