# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 17:21:43 by moel-idr          #+#    #+#              #
#    Updated: 2024/11/28 15:20:40 by moel-idr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

files = ft_printf \
		print_hex \
		print_int \
		print_ptr \
		print_str \
		print_u_int \


Compiler = cc

Flags = -Wall -Wextra -Werror

CFILES = $(files:%=%.c)

OBJS = $(files:%=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(Compiler) $(Flags) -c $< -o $@


clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean bonus fclean all