# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 12:39:58 by nsaraiva          #+#    #+#              #
#    Updated: 2025/08/07 12:57:23 by nsaraiva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = push_swap.c
OBJ = $(SRC:.c=.o)

LIBFT = include/libft
LIBFT_A = $(addprefix $(LIBFT), libft.a)

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g
LIBRARIES = -L$(LIBFT) -lft
NAME = push_swap

all : $(NAME) 

$(NAME) : $(SRC)
	$(CC) $(CCFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

