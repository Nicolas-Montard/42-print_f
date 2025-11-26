# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 15:10:14 by nmontard          #+#    #+#              #
#    Updated: 2025/11/26 11:51:34 by nmontard         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror -MMD -MP
CFILES = ft_printf.c ft_put_hex_nbr.c ft_put_memory.c ft_putchar.c ft_putnbr.c \
ft_putstr.c ft_putunbr.c
OBJECTS = $(CFILES:.c=.o)
DEPS  := $(OBJECTS:.o=.d)
NAME = libftprintf.a

all: $(NAME)

$(NAME) : $(OBJECTS) 
	ar rcs $@ $^

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

-include $(DEPS)
