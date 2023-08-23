#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_char - Prints a character to stdout.
 * @c: The character to print.
 * @cpt: Pointer to the character count.
 */
void print_char(char c, int *cpt)
{
	write(1, &c, 1);
	*cpt += 1;
}

/**
 * print_string - Prints a string to stdout.
 * @s: The string to print.
 * @cpt: Pointer to the character count.
 */
void print_string(char *s, int *cpt)
{
	while (*s != '\0')
	{
		write(1, s, 1);
		*cpt += 1;
		s++;
	}
}

/**
 * _printf - Produces output according to a format.
 * @format: The variable string that will be printed.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i = 0;
	va_list list;
	int cpt = 0;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			switch (format[i + 1])
			{
				case 'c':
					print_char(va_arg(list, int), &cpt);
					break;

				case 's':
					print_string(va_arg(list, char *), &cpt);
					break;

				case '%':
					print_char('%', &cpt);
					break;
			}
			i += 2;
		}
		else
		{
			print_char(format[i], &cpt);
			i++;
		}
	}

	va_end(list);
	return (cpt);
}
