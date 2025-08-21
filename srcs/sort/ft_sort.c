/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:35:26 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/20 15:40:35 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	worst_case(t_stack **stack);

int	ft_is_sort(t_stack *stack)
{
	t_stack	*head;
	t_stack	*next;

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
	t_stack	*previus;
	t_stack	*next;

	if (ft_is_sort(*stack))
		return ;
	next = (*stack)->next;
	previus = (*stack)->previus;
	if (worst_case(stack))
		return ;
	if (next->content > previus->content && next->content > (*stack)->content)
		ft_reverse_rotate(stack, 'a');
	else if ((*stack)->content > next->content && (
			*stack)->content > previus->content)
		ft_rotate(stack, 'a');
	else
		ft_swap(stack);
}

static int	worst_case(t_stack **stack)
{
	t_stack	*next;
	t_stack	*previus;

	next = (*stack)->next;
	previus = (*stack)->previus;
	if (((*stack)->content > next->content) && (
			next->content > previus->content))
	{
		ft_swap(stack);
		ft_reverse_rotate(stack, 'a');
		return (1);
	}
	if ((((*stack)->content < next->content) && (
				next->content > previus->content) && (
				previus->content > (*stack)->content)))
	{
		ft_swap(stack);
		ft_rotate(stack, 'a');
		return (1);
	}
	return (0);
}
