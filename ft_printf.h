/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: fstute <fstute@student.42wolfsburg.de>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/25 16:31:00 by fstute           #+#    #+#              */
/*   Updated: 2026/10/25 16:42:27 by fstute          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long nb);
int	ft_putnbr_hexa(unsigned long nbr, char type);
int	ft_putptr(void *ptr);

#endif
