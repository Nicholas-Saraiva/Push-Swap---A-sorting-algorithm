/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:07:38 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/21 19:07:39 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_positions	get_positions(t_stack **a, t_stack **b,
	t_stack *less_cost, t_stack *max_b)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;
	t_positions	pos;

	pos.a = 0;
	pos.b = 0;
	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a != less_cost && ++pos.a >= 0)
		tmp_a = tmp_a->next;
	while (tmp_b != max_b && tmp_b->next && ++pos.b >= 0)
		tmp_b = tmp_b ->next;
	return (pos);
}

t_stack	*get_great_small(t_stack *less_cost, t_stack *a)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = a;
	max = tmp;
	while (less_cost->content < tmp->content)
	{
		tmp = tmp->previus;
		if (tmp == max)
		{
			tmp = tmp ->next;
			break ;
		}
	}
	if (less_cost->content > tmp->content)
		tmp = tmp -> next;
	return (tmp);
}

int	before_middle(int size, int position)
{
	return (position < 0.5 + size / 2);
}

t_stack	*get_greater(t_stack *less_cost, t_stack *b)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = b;
	max = tmp;
	while (less_cost->content < tmp->content)
	{
		tmp = tmp->next;
		if (tmp == max)
			break ;
	}
	return (tmp);
}
