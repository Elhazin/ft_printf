/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:07:45 by abouzanb          #+#    #+#             */
/*   Updated: 2022/11/03 14:18:58 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr(long long k, int *ret)
{
	if (k < 0)
	{
		k = k * -1;
		*ret += ft_putchar('-');
	}
	if (k >= 10)
	{
		ft_putnbr(k / 10, &(*ret));
		k = k % 10;
	}
	if (k < 10)
	{
		*ret += ft_putchar(k + '0');
	}
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	formate(va_list arg, char c)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		ret += ft_putstr(va_arg(arg, char *));
	else if (c == 'd')
		ft_putnbr(va_arg(arg, int), &ret);
	else if (c == 'i')
		ft_putnbr(va_arg(arg, int), &ret);
	else if (c == '%')
		ret = ft_putchar('%');
	else if (c == 'x' || c == 'X')
		ret += dectohexa(va_arg(arg, unsigned int), c);
	else if (c == 'u')
		ft_putnbr(va_arg(arg, unsigned int), &ret);
	else if (c == 'p')
		ret += putptr((unsigned long long)va_arg(arg, void *));
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	int		i;
	va_list	arg;

	ret = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ret += formate(arg, str[i]);
		}
		else
			ret += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (ret);
}
