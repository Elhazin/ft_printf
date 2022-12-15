# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 15:10:43 by abouzanb          #+#    #+#              #
#    Updated: 2022/11/03 15:10:44 by abouzanb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

src = ft_printf.c ft_printf_utlis.c
obj = ft_printf.o ft_printf_utlis.o
NAME = libftprintf.a
CFLAGS = -Wall -Wextra  -Werror
all : $(NAME)
$(NAME) : $(obj)
	ar -rc $(NAME) $(obj)
clean :
	rm -f $(obj)
fclean : clean
	rm -f $(NAME)
re : fclean all
