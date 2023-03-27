#include "main.h"
<<<<<<< HEAD
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)

{

int i, printed = 0, printed_chars = 0;

int flags, width, precision, size, buff_ind = 0;

va_list list;

char buffer[BUFF_SIZE];

if (format == NULL)

return (-1);

va_start(list, format);

for (i = 0; format && format[i] != '\0'; i++)

{

if (format[i] != '%')

{

buffer[buff_ind++] = format[i];

if (buff_ind == BUFF_SIZE)

print_buffer(buffer, &buff_ind);

/* write(1, &format[i], 1);*/

printed_chars++;

}
=======
#include <stdarg.h>
>>>>>>> dd9aa6ec7612c1e88e8d9e747e2b50b11078feb2

else

{
<<<<<<< HEAD

print_buffer(buffer, &buff_ind);

flags = get_flags(format, &i);

width = get_width(format, &i, list);

precision = get_precision(format, &i, list);

size = get_size(format, &i);

++i;

printed = handle_print(format, &i, list, buffer,

flags, width, precision, size);

if (printed == -1)

return (-1);

printed_chars += printed;

}

}



print_buffer(buffer, &buff_ind);



va_end(list);



return (printed_chars);

}



=======
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

>>>>>>> dd9aa6ec7612c1e88e8d9e747e2b50b11078feb2
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

<<<<<<< HEAD
void print_buffer(char buffer[], int *buff_ind)

{

if (*buff_ind > 0)

write(1, &buffer[0], *buff_ind);



*buff_ind = 0;

=======
int handle_format_specifier(const char *format, int pos, va_list *args,
		char *buffer)
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
			/* unknown spec */
			break;
	}

	return (num_char);
>>>>>>> dd9aa6ec7612c1e88e8d9e747e2b50b11078feb2
}
