/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:21:26 by abouzanb          #+#    #+#             */
/*   Updated: 2022/11/03 15:34:27 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c )
{
	write(1, &c, 1);
	return (1);
}

int	print_ptr(char *ptr)
{
	int		i;

	i = ft_hexalen(ptr) - 1;
	write(1, "0x", 2);
	while (i >= 0)
	{
		write(1, &ptr[i], 1);
		i--;
	}
	return (ft_hexalen(ptr) + 2);
}

int	putptr(unsigned long long dec)
{
	int		x;
	char	ptr[17];
	char	*getptr;
	int		ret;

	getptr = "0123456789abcdef";
	ret = 0;
	x = 0;
	if (dec == 0)
	{
		ret = write(1, "0x0", 3);
		return (ret);
	}
	while (dec != 0)
	{
		ptr[x] = getptr[dec % 16];
		dec = dec / 16;
		x++;
	}
	ptr[x] = '\0';
	return (print_ptr(ptr));
}

int	print_hexa(char *hexa)
{
	int		i;

	i = ft_hexalen(hexa) - 1;
	while (i >= 0)
	{
		write(1, &hexa[i], 1);
		i--;
	}
	return (ft_hexalen(hexa));
}

int	dectohexa(unsigned int dec, const char format)
{
	int		x;
	char	hexa[17];
	char	*gethexa;
	int		ret;

	if (dec == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (format == 'x')
		gethexa = "0123456789abcdef";
	else if (format == 'X')
		gethexa = "0123456789ABCDEF";
	ret = 0;
	x = 0;
	while (dec != 0)
	{
		hexa[x] = gethexa[dec % 16];
		dec = dec / 16;
		x++;
	}
	hexa[x] = '\0';
	return (print_hexa(hexa));
}
