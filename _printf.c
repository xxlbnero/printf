#include "main.h"
#include <stdarg.h>

/**
 * _printf - Prints output according to a format.
 *
 * @format: A string containing zero or more directives to print.
 * @...: Variable arguments to be printed according to format.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i = 0, j = 0, len = 0;
    	va_list args;
    	char buffer[1024];

    	if (format == NULL)
        	return (-1);

    	va_start(args, format);

    	while (format[i])
    	{
        	if (format[i] == '%')
        	{
            		j = handle_format_specifier(format, i + 1, &args, buffer);
            		if (j == -1)
                		return (-1);
            		len += j;
            		i++;
        	}
        	else
        	{
            		buffer[len++] = format[i];
        	}
        	i++;
    	}

    	va_end(args);

    	buffer[len] = '\0';

   	return (len);
}
/**
 * handle_format_specifier - Handles a format specifier.
 *
 * @format: A string containing the format specifier.
 * @pos: The position of the format specifier in the format string.
 * @args: The variable arguments to be printed according to format.
 * @buffer: The buffer to store the resulting string.
 *
 * Return: The number of characters added to buffer, or -1 on error.
 */
int handle_format_specifier(const char *format, int pos, va_list *args, char *buffer)
{
	int num_char;

	switch (format[pos])
	{
		case 'd':
			num_char = sprintf(buffer, "%d", va_ag(args, int));
			break;
		case 'f':
			num_char = sprintf(buffer, "%f", va_arg(*args, double));
			break;
		case 's':
			num_char = sprintf(buffer, "%s", va_arg(*args, char *));
			break;
		case 'c':
			buffer[0] = va_arg(*args, int);
			buffer[1] = '\0';
			num_char = 1;
			break;
		default:
			// unknown spec
			break;
	}

	return (num_char);
}
