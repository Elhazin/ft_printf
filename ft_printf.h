/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:41:44 by abouzanb          #+#    #+#             */
/*   Updated: 2022/11/03 14:18:34 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		print_ptr(char *ptr);
int		putptr(unsigned long long dec);
int		print_hex(char *hexa);
int		dectohexa(unsigned int dec, const char format);
int		ft_hexalen(const char *str);
void	ft_putnbr(long long k, int *ret);
int		ft_putstr(const char *str);
int		ft_printf(const char *str, ...);
#endif
