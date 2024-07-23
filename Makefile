# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 16:13:24 by rohta             #+#    #+#              #
#    Updated: 2024/07/22 11:33:21 by rohta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_check.c ft_params_init.c ft_apply_csp.c \
      ft_apply_diuxX.c ft_write_string.c ft_write_number.c \
      ft_write_hexdecimal.c ft_write_unsigned.c ft_write_pointer.c \
      ft_write_number_sub.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft
LIBFT_OBJ = $(LIBFT_DIR)/ft_*.o

INC = -I ./libft 
LIB = -L $(LIBFT_DIR) -lft

all: $(NAME)

bonus: all

$(NAME): $(LIBFT_OBJ) $(OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFT_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT_OBJ):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	
re: fclean all

.PHONY: all bonus clean fclean re
