/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:02:22 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/20 15:51:18 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	modify_stacks(t_stack **a, t_stack **b,
				t_stack *less_cost, t_stack *max_b);
static void	modify_stacks_b(t_stack **a, t_stack **b,
				t_stack *less_cost, t_stack *max_b);
static void	final_sorting_a(t_stack **a);
int			both_rotate(int size_a, int size_b, t_positions pos, int mode);

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
	final_sorting_a(a);
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
	while (both_rotate(size_a, size_b, position, 0
		) && position.a-- && position.b--)
		ft_rr(a, b);
	while (both_rotate(size_a, size_b, position, 1
		) && position.a++ && position.b++)
		ft_rrr(a, b);
	while (before_middle(size_a, position.a) && *a != min_cost && position.a--)
		ft_rotate(a, 'a');
	while (before_middle(size_b, position.b) && *b != max_b && position.b--)
		ft_rotate(b, 'b');
	while (!before_middle(size_a, position.a) && *a != min_cost && position.a++)
		ft_reverse_rotate(a, 'a');
	while (!before_middle(size_b, position.b) && *b != max_b && position.b++)
		ft_reverse_rotate(b, 'b');
	ft_push(a, b, 'b');
}

int	both_rotate(int size_a, int size_b, t_positions pos, int mode)
{
	if (mode == 0)
		return ((!(size_a - pos.a) || !(size_b - pos.b)) && before_middle(
				size_a, pos.a) && before_middle(size_b, pos.b));
	return ((!(size_a - pos.a) || !(size_b - pos.b)
		) && !before_middle(size_a, pos.a
		) && !before_middle(size_b, pos.b));
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

static void	final_sorting_a(t_stack **a)
{
	int		size;
	t_stack	*max_b;

	max_b = lst_max_value(a);
	max_b->cost += 1;
	size = lst_size(*a) + 1;
	if ((!(size % 2) && max_b->cost < size / 2) || (
			max_b->cost < size / 2 + 1))
		while ((*a) != max_b->next)
			ft_rotate(a, 'a');
	else
		while ((*a) != max_b->next)
			ft_reverse_rotate(a, 'a');
}
