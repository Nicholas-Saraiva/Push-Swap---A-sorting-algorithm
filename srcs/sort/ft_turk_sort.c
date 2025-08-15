/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:02:22 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/15 18:51:25 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*return_max_value(t_stack *stack);
static void	fill_cost(t_stack **a, t_stack **b);

void	turk_sort(t_stack **a, t_stack **b)
{
	t_stack	*max;

	ft_push(a, b);
	ft_push(a, b);
	max = return_max_value(t_stack *b);

	
}

static void	fill_cost(t_stack **a, t_stack **b)
{
	t_stack	*max;
	t_stack	*head;
	int		i;

	head = a;
	max = return_max_value(t_stack *b);
	// if a.content > max.content, how much steps max.content will have to make to be on top.
	// if not, check with outher's values on stack. If a.content is the minimun, just push.
	while (a->next != head)
	{
		if (a->content > max->content)
		{
			
		}
	}
}

static t_stack	*return_max_value(t_stack *stack)
{
	t_stack *head;
	t_stack *next;
	t_stack *max;
	
	head =  stack;
	max = head;
	while (stack && stack -> next && stack -> next != head)
	{
		stack = stack->next;
		if (max->content < stack->content)
			max = stack;
	}
	return (max);
}
