#include "main.h"

/**
 * buffer_overflow_check - if writing overbuffer space, print everything,
 * reset buffer and write to reset buffer
 * @buffer: buffer holding string to print
 * @len: used buffer space
 * @Return: buffer space
 */

int buffer_overflow_check(char *buffer, int len)
{
	if (len > 1020)
	{
		write(1, buffer, len);
		len = 0;
	}
	return (len);
}

/**
 * _printf - mini printf version
 * @format: initial string with all identifiers
 * Return: expanded string
 */

int _printf(const char * format, ...)
{
	va_list list;
	char *buffer;
	char *str;
	int len = 0; 
	int full_len = 0; 
	int i = 0;
       	int j = 0;

	char* (*f)(va_list);

	if (format == NULL)
		return (-1);

	buffer = create_buffer();

	if (buffer == NULL)
		return (-1);

	va_start(list, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			/* copy format to buffer */
			len = buffer_overflow_check (buffer, len);
			buffer[len] = format[i];
			len++; i++; full_len++;
		}
		else
		{
			i++; /* if % check next character*/

			if (format[i] == '\0') /* % at end of string*/
			{
				va_end(list);
				free(buffer);
				return (-1);
			}
			if (format[i] == '%') /* double % */
			{
				len = buffer_overflow_check(buffer, len);
				buffer[len] = format[i];
				len++; i++; full_len++;
			}
			else 
			{
				f = get_function(format[i]);

				if (f == NULL)
				{
					len = buffer_overflow_check(buffer, len);
					buffer[len] = '%'; full_len++;
					buffer[len] = format[i]; full_len++;
				}
				else
				{
					str = f(list);
					if (str == NULL)
					{
						va_end(list);
						free(buffer);
						return (-1);
					}	
				}
				if (format[i] == 'c' && str[0] == '\0')
				{
					len = buffer_overflow_check(buffer, len);
					buffer[len] = '\0';
					len++;
					full_len++;
				}
				while (str[j] != '\0')
				{
					len = buffer_overflow_check(buffer, len);
					buffer[len] = str[j];
					len++;
					full_len++; j++;
				}
				free(str);

			}
			
		} i++;
			
	
	}

	write_buffer(buffer, len, list);
	return (full_len);	
}

int main(void)
{
	_printf("C");
	return (0);
}
