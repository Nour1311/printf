#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: the variable string that will be printed.
 * Return: number of characters printed.
 */
 
int _printf(const char *format, ...)
{
        int i = 1;
        va_list list;
        int cpt = 0;
        
        if (format == NULL)
        	return (-1);
        	
        va_start (list, format);

        while (format)
        {
                if ((format[0] == ('\"')) || (format[0] == ('\'')))
                        {
                                while (format[i] != "\0")
                                {
                                        if (format[i] == "%")
                                        {
                                                if (format[i + 1] == "c")
                                                {
                                                        char c = va_arg(list, char);
                                                        write(1, &c, 1);
                                                        cpt++;
                                                }

                                                if (format[i + 1] == "s")
                                                {
                                                        char *s = va_arg(list, (char *));
                                                        while (*s)
                                                        {
                                                                write(1, &s, 1);
                                                                cpt++;
                                                                s++;
                                                        } 
                                                }

                                                if (format[i + 1] == "%")
                                                {
                                                        write(1, "%", 1);
                                                        cpt++;                                          
                                                }

                                                i++;

                                        }
                                        else
                                        {
                                                write(1, format[i], 1);
                                                cpt++;
                                	        i++;
                                        }
                                        
                                }
                        }
        }
        va_end(list);
        return (cpt);
}
