# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 12:39:58 by nsaraiva          #+#    #+#              #
#    Updated: 2025/08/20 14:49:35 by nsaraiva         ###   ########.fr        #
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
LIBFT_A = $(addprefix $(LIBFT)/, libft.a)
PRINTF = includes/ft_printf
PRINTF_A = $(addprefix $(PRINTF)/, ft_printf.a)

CC = cc
CCFLAGS = -Wall -Wextra -Werror -Iheader -g
LIBRARIES = -L$(LIBFT) -lft -L$(PRINTF) -lftprintf
NAME = push_swap
BONUS_NAME = checker

all: $(LIBFT_A) $(PRINTF_A) $(NAME)

bonus: $(LIBFT_A) $(PRINTF_A) $(BONUS_NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBRARIES) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CCFLAGS) $(BONUS_OBJ) $(LIBRARIES) -o $(BONUS_NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT) all
$(PRINTF_A):
	$(MAKE) -C $(PRINTF) all

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(BONUS_OBJ)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re
