/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:02:22 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/04 14:53:56 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	modify_stacks(t_stack **a, t_stack **b,
				t_stack *less_cost, t_stack *max_b);
static void	modify_stacks_b(t_stack **a, t_stack **b,
				t_stack *less_cost, t_stack *max_b);
static void	final_sorting(t_stack **a, char c);
static void	both_rotate(t_stack **a, t_stack **b,
				t_stack *min_cost, t_stack *max_b);

void	turk_sort(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*max_b;
	t_stack	*less_cost;

	ft_push(a, b, 'b');
	ft_push(a, b, 'b');
	size = lst_size(*a) + 1;
	while (--size > 3)
	{
		max_b = lst_max_value(b);
		fill_cost(a, max_b);
		less_cost = find_less_cost(a);
		modify_stacks(a, b, less_cost, max_b);
	}
	ft_tiny_sort(a);
	while (*b)
		modify_stacks_b(a, b, lst_max_value(a), *b);
	final_sorting(a, 'a');
}

static void	modify_stacks(t_stack **a, t_stack **b,
	t_stack *min_cost, t_stack *max_b)
{
	t_positions	position;
	int			size_a;
	int			size_b;

	size_a = lst_size(*a);
	size_b = lst_size(*b);
	max_b = get_greater(min_cost, max_b);
	position = get_positions(a, b, min_cost, max_b);
	both_rotate(a, b, min_cost, max_b);
	while (before_middle(size_a, position.a) && *a != min_cost)
		ft_rotate(a, 'a');
	while (before_middle(size_b, position.b) && *b != max_b)
		ft_rotate(b, 'b');
	while (!before_middle(size_a, position.a) && *a != min_cost)
		ft_reverse_rotate(a, 'a');
	while (!before_middle(size_b, position.b) && *b != max_b)
		ft_reverse_rotate(b, 'b');
	ft_push(a, b, 'b');
}

static void	both_rotate(t_stack **a, t_stack **b,
	t_stack *min_cost, t_stack *max_b)
{
	t_positions	position;
	int			size_a;
	int			size_b;

	size_a = lst_size(*a);
	size_b = lst_size(*b);
	max_b = get_greater(min_cost, max_b);
	position = get_positions(a, b, min_cost, max_b);
	while (*a != min_cost && *b != max_b && (before_middle(
				size_a, position.a) && (before_middle(size_b, position.b
				) || position.a >= size_b)))
		ft_rr(a, b, '1');
	while (!before_middle(size_a, position.a) && (!before_middle(
				size_b, position.b) || (size_a - position.a) >= size_b
		) && *a != min_cost && *b != max_b)
		ft_rrr(a, b, '1');
	while (before_middle(size_b, position.b) && (position.b >= size_a
		) && *a != min_cost && *b != max_b)
		ft_rr(a, b, '1');
	while (!before_middle(size_b, position.b) && ((size_b - position.b
			) >= size_a) && *a != min_cost && *b != max_b)
		ft_rrr(a, b, '1');
}

static void	modify_stacks_b(t_stack **a, t_stack **b,
	t_stack *less_cost, t_stack *max_b)
{
	t_positions	pos;
	int			size_a;

	size_a = lst_size(*a);
	less_cost = get_great_small(max_b, less_cost);
	pos = get_positions(a, b, less_cost, max_b);
	while (pos.a < (0.5 + size_a / 2) && *a != less_cost)
	{
		ft_rotate(a, 'a');
		pos.a--;
	}
	while (pos.a >= (0.5 + size_a / 2) && *a != less_cost)
	{
		ft_reverse_rotate(a, 'a');
		pos.a++;
	}
	ft_push(b, a, 'a');
}

static void	final_sorting(t_stack **a, char c)
{
	int		size;
	t_stack	*max_b;

	max_b = lst_max_value(a);
	max_b->cost += 1;
	size = lst_size(*a) + 1;
	if ((!(size % 2) && max_b->cost < size / 2) || (
			max_b->cost < size / 2 + 1))
		while ((*a) != max_b->next)
			ft_rotate(a, c);
	else
		while ((*a) != max_b->next)
			ft_reverse_rotate(a, c);
}
