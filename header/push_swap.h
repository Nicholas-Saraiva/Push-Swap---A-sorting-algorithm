/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:32:39 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/15 16:06:59 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct	s_stack
{
	int		content;
	int		cost;
	void	*next;
	void	*previus;
}	t_stack;

//----------Error-Utils
void	ft_error(t_stack **a, t_stack **b);
void	free_char_array(char **array);

//----------List-Utils
t_stack	*lstnew(int content);
void	lstclear(t_stack **lst);
void	lstadd_front(t_stack **lst, t_stack *new);
void	lstadd_back(t_stack **lst, t_stack *new);
int		check_lstrepetition(t_stack **lst, int number);

//----------Utils
int		ft_strtoi(const char *split, int *number);
int 	*new_value(int value);
int		get_size(char **split);
int		ft_abs(const int number);
int		lst_size(t_stack *lst);


//----------srcs/operations
void	ft_swap(t_stack **stack);
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);
void	ft_push(t_stack **head1, t_stack **head2);

//---------srcs/sort
int		ft_is_sort(t_stack *stack);
void	ft_tiny_sort(t_stack **stack);
void	turk_sort(t_stack **a, t_stack **b);

#endif
