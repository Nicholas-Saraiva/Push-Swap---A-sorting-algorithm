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

static t_stack	*lst_max_value(t_stack **stack);
static void		fill_cost(t_stack **a, t_stack **b);
int				make_cost(t_stack **a, t_stack *max, int position);
int				create_cost(int	cost1, int cost2, int size_a, int size_b);

void	turk_sort(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	ft_push(a, b);
	
	fill_cost(a, b);
}

static void	fill_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack *max;
	int		i;

	tmp = *a;
	max = lst_max_value(b);
	i = 0;
	while (tmp)
	{
		tmp->cost = make_cost(&tmp, max, i);
		tmp = tmp -> next;
		if (tmp == *a)
			break;
		i++;
	}
}

int	make_cost(t_stack **a, t_stack *max, int position)
{
	t_stack *tmp;
	int		cost;
	int		size_a;
	int		size_b;
	
	cost = 0;
	tmp = max;
	size_a = lst_size(*a);
	size_b = lst_size(max);
	while (tmp)
	{
		if ((*a)->content > tmp->content)
		{
			if (cost + max->cost > size_b)
				cost = cost + max->cost - size_b;
			else
				cost = cost + max->cost;
			return (create_cost(position, cost, size_a, size_b));
		}
		if (tmp -> next == max)
			break;
		tmp = tmp -> next;
		cost++;
	}
	return (create_cost(position, max->cost, size_a, size_b));
}

int	create_cost(int	cost1, int cost2, int size_a, int size_b)
{
	if ((cost1 > size_a / 2 + 1 && cost2 > size_b / 2 + 1) || (
		cost1 <= size_a / 2 + 1 && cost2 <= size_b / 2 + 1
	))
		if (cost1 == cost2)
			return (cost2 - + 1);
		else
			return (ft_abs(cost1 - cost2) + 1);
	else
		return (cost1 + cost2 + 1);
}

static t_stack	*lst_max_value(t_stack **stack)
{
	t_stack *head;
	t_stack *max;
	int		position;
	
	head =  (*stack);
	max = head;
	position = 0;
	while ((*stack) && (*stack) -> next && (*stack) -> next != head)
	{
		(*stack) = (*stack)->next;
		position++;
		if (max->content < (*stack)->content)
			max = (*stack);
	}
	max->cost = position;
	return (max);
}
