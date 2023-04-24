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

int _printf(const char *format, ...)
{
	int len = 0, full_len = 0, i = 0, j = 0;
	va_list list;
	char *buffer, *string;


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
			len = buffer_overflow_check(buffer, len);
			buffer[len] = format[i];
			len++; i++;
			full_len++;
		}
		else
		{
			i++; /* if % ,check next character to find function */

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
				len++;full_len++;
			}
			else 
			{
				f = get_function(format[i]);

				if (f == NULL)
				{
					len = buffer_overflow_check(buffer, len);
					buffer[len] = '%'; full_len++;len++;
					buffer[len] = format[i]; full_len++;i++;
				}
				else
				{
					string = f(list);
					if (string == NULL)
					{
						va_end(list);
						free(buffer);
						return (-1);
					}	
				
					if (format[i] == 'c' && string[0] == '\0')
					{
						len = buffer_overflow_check(buffer, len);
						buffer[len] = '\0';
						len++;
						full_len++;
					}
					while (string[j] != '\0')
					{
						len = buffer_overflow_check(buffer, len);
						buffer[len] = string[j];
						len++;
						full_len++; j++;
					}
					free(string);
				}
				

			}
			i++;
			
		}
			
		
	}
	write_buffer(buffer, len, list);
	return (full_len);	
}

int main(void)
{
	_printf("My name is %s", "marlen");
	return (0);
}
