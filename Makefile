# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tvan-cit <tvan-cit@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/06 15:19:06 by tvan-cit       #+#    #+#                 #
#    Updated: 2019/12/19 11:17:21 by tvan-cit      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_printf_lib_1.c \
		ft_printf_lib_2.c \
		ft_printf_flag_and_type_utils.c \
		ft_printf_struct_utils.c \
		ft_printf_print_character.c \
		ft_printf_print_percentage.c \
		ft_printf_print_str.c \
		ft_printf_print_digit.c \
		ft_printf_print_pointer.c \
		ft_printf_print_hex.c \
		ft_printf_print_unsigned_int.c \
		ft_printf.c \

LIB	  =	$(subst .c,.o, $(SRC))

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rc $(NAME) $(LIB)

clean:
	/bin/rm -f $(LIB) $(BLIB)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
