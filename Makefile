# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 12:39:58 by nsaraiva          #+#    #+#              #
#    Updated: 2025/08/15 16:04:39 by nsaraiva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c
SRC += utils/ft_error.c utils/ft_lst_utils.c utils/ft_utils.c
SRC += srcs/ft_operations.c
SRC += srcs/sort/ft_sort.c
OBJ = $(SRC:.c=.o)

LIBFT = includes/libft 
LIBFT_A = $(addprefix $(LIBFT)/, libft.a)
PRINTF = includes/ft_printf
PRINTF_A = $(addprefix $(LIBFT)/, ft_printf.a)

CC = cc
CCFLAGS = -Wall -Wextra -Werror -Iheader -g
LIBRARIES = -L$(LIBFT) -lft -L$(PRINTF) -lftprintf
NAME = push_swap

all: $(LIBFT_A) $(PRINTF_A) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBRARIES) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT)
$(PRINTF_A):
	make -C $(PRINTF)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT)
	make clean -C $(PRINTF)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)
	make fclean -C $(PRINTF)

re: fclean all

.PHONY: all clean fclean re

