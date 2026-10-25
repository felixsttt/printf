#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
	{
		if (write(1, &str[len], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_putnbr(long nb)
{
	int	len;
	int	ret;

	len = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		nb = -nb;
	}
	if (nb > 9)
	{
		ret = ft_putnbr(nb / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	if (ft_putchar(nb % 10 + '0') == -1)
		return (-1);
	return (len + 1);
}

int	ft_putnbr_hexa(unsigned long nbr, char type)
{
	char	*base;
	int		len;
	int		ret;

	if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 0;
	if (nbr > 15)
	{
		ret = ft_putnbr_hexa(nbr / 16, type);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	if (ft_putchar(base[nbr % 16]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	ret;

	if (!ptr)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x");
	if (len == -1)
		return (-1);
	ret = ft_putnbr_hexa((unsigned long)ptr, 'x');
	if (ret == -1)
		return (-1);
	return (len + ret);
}