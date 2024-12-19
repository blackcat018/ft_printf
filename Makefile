# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 17:21:43 by moel-idr          #+#    #+#              #
#    Updated: 2024/12/02 20:53:02 by moel-idr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

files = ft_printf \
		print_hex \
		print_int \
		print_ptr \
		print_str \
		print_u_int \

BSRC = bonus/ft_flag_check_bonus\
	   bonus/ft_printf_bonus\
	   bonus/ft_printf_bonus\
	   bonus/print_hex_bonus\
	   bonus/print_int_bonus\
	   bonus/print_ptr_bonus\
	   bonus/print_str_bonus\
	   bonus/print_u_int_bonus
	   

Compiler = cc

Flags = -Wall -Wextra -Werror

CFILES = $(files:%=%.c)
BNDILES = $(BSRC:%=%.c)

OBJS = $(files:%=%.o)
BOBJS = $(BSRC:%=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

bonus:$(BOBJS)
	ar rcs $(NAME) $(BOBJS)

%.o: %.c ft_printf.h
	$(Compiler) $(Flags) -c $< -o $@

bonus/%.o:bonus/%.c bonus/ft_printf_bonus.h
	$(Compiler) $(Flags) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean