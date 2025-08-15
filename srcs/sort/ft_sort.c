/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:35:26 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/15 16:59:05 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "push_swap.h"

static int	worst_case(t_stack **stack);

int	ft_is_sort(t_stack *stack)
{
	t_stack *head;
	t_stack *next;

	head = stack;
	while (stack && stack -> next && stack -> next != head)
	{
		next = stack -> next;
		if (stack -> content > next -> content)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

void	ft_tiny_sort(t_stack **stack)
{
	t_stack *next;

	if (ft_is_sort(*stack))
		return ;
	next = (*stack) -> next;
	if (worst_case(stack))
		return ;
	if ((*stack)->content > next->content)
		ft_swap(stack);
	else
		ft_reverse_rotate(stack);
}

static int	worst_case(t_stack **stack)
{
	t_stack	*next;
	t_stack	*previus;

	next = (*stack) -> next;
	previus = (*stack) -> previus;
	if (((*stack)->content > next->content) && (
				next->content > previus->content))
	{
		ft_swap(stack);
		ft_reverse_rotate(stack);
		return (1);
	}
	if (((*stack)->content < next->content) && (
				next->content > previus->content) && (
					previus->content > (*stack)->content))
	{
		ft_swap(stack);
		ft_rotate(stack);
		return (1);
	}
	return (0);
}
