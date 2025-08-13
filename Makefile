# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 12:39:58 by nsaraiva          #+#    #+#              #
#    Updated: 2025/08/12 10:28:57 by nsaraiva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c
SRC += utils/ft_error.c utils/ft_lst_utils.c utils/ft_utils.c
OBJ = $(SRC:.c=.o)

LIBFT = includes/libft 
LIBFT_A = $(addprefix $(LIBFT)/, libft.a)

CC = cc
CCFLAGS = -Wall -Wextra -Werror -Iheader -g
LIBRARIES = -L$(LIBFT) -lft
NAME = push_swap

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBRARIES) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT)

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

