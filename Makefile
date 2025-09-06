# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 12:39:58 by nsaraiva          #+#    #+#              #
#    Updated: 2025/09/06 12:23:28 by nsaraiva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c
SRC += utils/ft_error.c utils/ft_lst_utils.c utils/ft_more_lst_utils.c utils/ft_utils.c
SRC += srcs/operations/ft_single_op.c srcs/operations/ft_dual_op.c
SRC += srcs/sort/ft_sort.c srcs/sort/ft_turk_sort.c srcs/sort/turk_cost_utils.c srcs/sort/turk_utils.c
OBJ = $(SRC:.c=.o)

BONUS_SRC = checker_bonus.c
BONUS_SRC += utils/ft_error.c utils/ft_lst_utils.c utils/ft_more_lst_utils.c utils/ft_utils.c
BONUS_SRC += srcs/operations/ft_single_op.c srcs/operations/ft_dual_op.c
BONUS_SRC += srcs/sort/ft_sort.c srcs/sort/ft_turk_sort.c srcs/sort/turk_cost_utils.c srcs/sort/turk_utils.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

LIBFT = includes/libft 
PRINTF = includes/ft_printf
GNL = includes/get_next_line

CC = cc
CCFLAGS = -Wall -Wextra -Werror -Iheader -g
LIBRARIES = -L$(LIBFT) -lft -L$(PRINTF) -lftprintf

NAME = push_swap
BONUS_NAME = checker

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(PRINTF)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBRARIES) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(MAKE) -C $(PRINTF)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(GNL) all
	$(CC) $(CCFLAGS) $(BONUS_OBJ) $(LIBRARIES) -L$(GNL) -lget -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(BONUS_OBJ)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean
	$(MAKE) -C $(GNL) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean
	$(MAKE) -C $(GNL) fclean

re: fclean all

.PHONY: all clean fclean re
