/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:49:56 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/21 19:07:34 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	make_cost(t_stack **a, t_stack *max, int position);
static int	create_cost(int cost1, int cost2, int size_a, int size_b);

t_stack	*find_less_cost(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*less_cost;

	less_cost = *a;
	tmp = *a;
	while (tmp)
	{
		tmp = tmp -> next;
		if (tmp->cost < less_cost->cost)
			less_cost = tmp;
		if (tmp == *a)
			break ;
	}
	return (less_cost);
}

void	fill_cost(t_stack **a, t_stack *max)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		tmp->cost = make_cost(&tmp, max, i);
		tmp = tmp -> next;
		if (tmp == *a)
			break ;
		i++;
	}
}

static int	make_cost(t_stack **a, t_stack *max, int position)
{
	t_stack	*tmp;
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
			return (create_cost(position, cost + max->cost, size_a, size_b));
		if (tmp -> next == max)
			break ;
		tmp = tmp -> next;
		cost++;
	}
	return (create_cost(position, max->cost, size_a, size_b));
}

static int	create_cost(int cost1, int cost2, int size_a, int size_b)
{
	int	reverse_rotate;

	reverse_rotate = 0;
	if ((!(size_a % 2) && cost1 > size_a / 2) || (
			cost1 >= size_a / 2 + 1))
	{
		cost1 = size_a - cost1;
		reverse_rotate++;
	}
	if (cost2 > size_b)
		cost2 -= size_b;
	if ((!(size_b % 2) && cost2 > size_b / 2) || (
			cost2 >= size_b / 2 + 1))
	{
		cost2 = size_b - cost2;
		reverse_rotate++;
	}
	if ((reverse_rotate == 2 || reverse_rotate == 0) || (
			(cost2 && cost1 >= size_b) || (cost1 && cost2 >= size_a)) || (
			reverse_rotate == 1 && (
				cost2 == size_b / 2 || cost1 == size_a / 2)))
		return (ft_max(cost1, cost2) + 1);
	return (cost1 + cost2 + 1);
}
