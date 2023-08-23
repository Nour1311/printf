#include "main.h"
#include <unistd.h>
#include <stdarg.h>

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
				{
					char c = va_arg(list, int);
					write(1, &c, 1);
					cpt++;
					break;
				}

				case 's':
				{
					char *s = va_arg(list, char *);
					while (*s != '\0')
					{
						write(1, s, 1);
						cpt++;
						s++;
					}
					break;
				}

				case '%':
					write(1, "%", 1);
					cpt++;
					break;
			}
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			cpt++;
			i++;
		}
	}

	va_end(list);
	return (cpt);
}
