/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:32:39 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/03 12:57:28 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack	t_stack;

typedef struct s_stack
{
	int		content;
	int		cost;
	t_stack	*next;
	t_stack	*previus;
}	t_stack;

typedef struct s_positions
{
	int	a;
	int	b;
}	t_positions;

//----------Error-Utils
void		ft_error(t_stack **a, t_stack **b);
void		free_char_array(char **array);

//----------List-Utils
t_stack		*lstnew(int content);
void		lstclear(t_stack **lst);
void		lstadd_front(t_stack **lst, t_stack *new);
void		lstadd_back(t_stack **lst, t_stack *new);
int			check_lstrepetition(t_stack **lst, int number);

//----------List-More-Utils
t_stack		*lst_max_value(t_stack **stack);
int			check_lstrepetition(t_stack **lst, int number);

//----------Utils
int			ft_strtoi(const char *split, int *number);
int			*new_value(int value);
int			get_size(char **split);
int			ft_max(const int a, const int b);
int			lst_size(t_stack *lst);

//----------srcs/operations/single
void		ft_swap(t_stack **stack, char c);
void		ft_rotate(t_stack **stack, char c);
void		ft_reverse_rotate(t_stack **stack, char c);
void		ft_push(t_stack **head1, t_stack **head2, char c);

//----------srcs/operations/dual
void		ft_ss(t_stack **a, t_stack **b, char c);
void		ft_rr(t_stack **a, t_stack **b, char c);
void		ft_rrr(t_stack **a, t_stack **b, char c);

//---------srcs/sort
int			ft_is_sort(t_stack *stack);
void		ft_tiny_sort(t_stack **stack);
void		turk_sort(t_stack **a, t_stack **b);

//---------srcs/sort/turk-utils
t_positions	get_positions(t_stack **a, t_stack **b,
				t_stack *less_cost, t_stack *max_b);
t_stack		*get_great_small(t_stack *less_cost, t_stack *a);
t_stack		*get_greater(t_stack *less_cost, t_stack *b);
int			before_middle(int size, int position);

//---------srcs/sort/turk-cost-utils
t_stack		*find_less_cost(t_stack **a);
void		fill_cost(t_stack **a, t_stack *max);

#endif
