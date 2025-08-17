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
	int	size;

	size = lst_size(a) + 1;
	ft_push(a, b);
	ft_push(a, b);
	while (--size > 3)
	{
		fill_cost(a, b);
	}
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
			return (create_cost(position, cost + max->cost, size_a, size_b));
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
	int	reverse_rotate;

	reverse_rotate = 0;
	if (( (float) (size_a % 2) == 0 && cost1 >= size_a / 2) || (
		cost1 >= size_a / 2 + 1))
	{
		cost1 = size_a - cost1;
		reverse_rotate++;
	}
	if (cost2 >= size_b)
		cost2 -= size_b;
	if ((!(size_b % 2) && cost2 >= size_b / 2) || (
		cost2 >= size_b / 2 + 1))
		reverse_rotate++;
	if (reverse_rotate == 2 || reverse_rotate == 0)
	{	
		if (cost1 == cost2)
			return (cost2 + 1);
		else
			return (ft_max(cost1, cost2) + 1);
	}
	if (reverse_rotate == 1 && (!(size_a % 2) || !(size_b % 2)))
		return (ft_max(cost1, cost2) + 1);
	return (cost1 + cost2 + 1);
}

static t_stack	*lst_max_value(t_stack **stack)
{
	t_stack *tmp;
	t_stack *max;
	int		position;
	
	tmp =  (*stack);
	max = tmp;
	max -> cost = 0;
	position = 0;
	while (tmp && tmp -> next && tmp -> next != *stack)
	{
		tmp = tmp->next;
		position++;
		if (max->content < tmp->content)
		{
			max = tmp;
			max->cost = position;
		}
	}
	return (max);
}
