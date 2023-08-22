#include "main.h"
/**
* print_format- checks for the format specifier after '%'
* @ap: list of variadic arguments
* @spec: the format specifier to be checked by @print_format
* Return: return number of printed characters
*/

int print_format(char spec, va_list ap)
{
	int count = 0;

	if (spec == 'c')
	count += _putchar(va_arg(ap, int));
	else if (spec == 's')
	count += print_str(va_arg(ap, char *));
	else if (spec == 'i' || spec == 'd')
	count += print_digit((long)(va_arg(ap, int)), 10);
	else if (spec == 'x')
	count += print_hexa((long)(va_arg(ap, unsigned int)), 16, 'x');
	else if (spec == 'X')
	count += print_hexa((long)(va_arg(ap, unsigned int)), 16, 'X');
	else if (spec == 'u')
	count += print_digit((long)(va_arg(ap, unsigned int)), 10);
	else if (spec == 'o')
	count += print_digit((long)(va_arg(ap, unsigned int)), 8);
	else if (spec == 'p')
	{
	count += write(1, "0x", 2);
	count += print_digit((long)(va_arg(ap, void *)), 16);
	}
	else if (spec == 'b')
	count += print_digit((long)(va_arg(ap, void *)), 2);
	else if (spec == '%')
	count += _putchar('%');
	else
	count += write(1, &spec, 1);
	return (count);
}