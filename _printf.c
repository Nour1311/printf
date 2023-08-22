#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int i;
	va_list list;


	while (format)
	{
		// write until 
