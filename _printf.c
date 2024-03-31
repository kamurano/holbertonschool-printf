#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
/**
 * _printf - print string
 * @format: format
 * Return: letter count
 */
int _printf(const char *format, ...)
{
	va_list ptr;
	int j = 0, r = 0;
	
	if (!format)
	{
		return;
	}
	va_start(ptr, format);
	while (*(format + j))
	{
		if (*(format + j) == '%' && *(format + j + 1) == 'c')
		{
			r = print_char(r, (char)va_arg(ptr, int)), j += 2;
		}
		else if (*(format + j) == '%' && *(format + j + 1) == 's')
		{
			r = print_string(r, va_arg(ptr, char *)), j += 2;
		}
		else if (*(format + j) == '%' && (*(format + j + 1) == 'd' ||
		*(format + j + 1) == 'i'))
		{
			r += print_decimal(va_arg(ptr, int)), j += 2;
		}
		else
		{
			r++, _putchar(*(format + j)), j++;
		}
}
