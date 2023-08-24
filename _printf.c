#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _print_char - Prints a character to stdout.
 * @c: The character to print.
 * @printed_chars: Pointer to the character count.
 */
void _print_char(char c, int *printed_chars)
{
    write(1, &c, 1);
    (*printed_chars)++;
}

/**
 * _print_string - Prints a string to stdout.
 * @s: The string to print.
 * @printed_chars: Pointer to the character count.
 *
 * Return: Number of characters printed.
 */
void _print_string(char *s, int *printed_chars)
{
    while (*s)
    {
        write(1, s, 1);
        (*printed_chars)++;
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
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    _print_char(va_arg(args, int), &printed_chars);
                    break;

                case 's':
                    _print_string(va_arg(args, char *), &printed_chars);
                    break;

                case '%':
                    _print_char('%', &printed_chars);
                    break;

                default:
                    write(1, format, 1);
                    printed_chars++;
            }
        }
        else
        {
            write(1, format, 1);
            printed_chars++;
        }

        format++;
    }

    va_end(args);
    return (printed_chars);
}
