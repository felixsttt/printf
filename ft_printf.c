#include "ft_printf.h"

static int	ft_format(char c, va_list args)
{
	if (c == 'c') // a single character
		return (ft_putchar(va_arg(args, int)));
	if (c == 's') // a string/text
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p') // a memory address as a hexadecimal number
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i') // a signed decimal number
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u') // a unsigned decimal number
		return (ft_putnbr(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X') // same as 'u' but using lowercase letters // 'X' uppercase
		return (ft_putnbr_hexa(va_arg(args, unsigned int), c));
	if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;
	int		ret;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ret = ft_format(*str, args);
		}
		else
			ret = write(1, str, 1);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		len += ret;
		str++;
	}
	va_end(args);
	return (len);
}