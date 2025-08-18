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
static void		fill_cost(t_stack **a, t_stack *max);
int				make_cost(t_stack **a, t_stack *max, int position);
int				create_cost(int	cost1, int cost2, int size_a, int size_b);
static t_stack	*find_less_cost(t_stack **a);
static void	modify_stacks(t_stack **a, t_stack **b, 
	t_stack *less_cost, t_stack *max_b);
static t_positions	get_positions(t_stack **a, t_stack **b, 
	t_stack *less_cost, t_stack *max_b);

void	turk_sort(t_stack **a, t_stack **b)
{
	t_stack *a1;
	t_stack *b1;
	t_stack *first;
	int	size;
	t_stack *max_b;
	t_stack *less_cost;

	ft_push(a, b);
	ft_push(a, b);
	size = lst_size(*a) + 1;
	max_b = lst_max_value(b);
	while (--size > 3)
	{ 

		fill_cost(a, max_b);
		less_cost = find_less_cost(a);
		modify_stacks(a, b, less_cost, max_b);
		max_b = lst_max_value(b);
		a1 = (*a);
		first = a1;
		b1 = (*b);
	ft_printf("\nSTACK A\n");
	while (a1->next != first)
	{
		ft_printf("Number: %d				Cost: %d\n", a1->content, a1->cost);
		a1 = a1->next;
	}
		ft_printf("Number: %d				Cost: %d\n", a1->content, a1->cost);
	ft_printf("\nSTACK B\n");
	first = b1;
	while (b1->next != first)
	{
		ft_printf("Number: %d				Cost: %d\n", b1->content, b1->cost);
		b1 = b1->next;
	}
		ft_printf("Number: %d				Cost: %d\n", b1->content, b1->cost);
	}
	ft_printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
}

int	before_middle(int size, int position)
{
	return ((!(size % 2) && size - position < size / 2) || ( 
		size - position < size / 2 + 1));
}

t_stack	*get_greater(t_stack *less_cost, t_stack *b)
{
	t_stack	*tmp;
	t_stack *max;

	tmp = b;
	max = tmp;
	while (less_cost->content < tmp->content)
	{
		tmp = tmp->next;
		if (tmp == max)
			break;
	}
	return (tmp);
}

static void	modify_stacks(t_stack **a, t_stack **b, 
	t_stack *less_cost, t_stack *max_b)
{
	t_positions	pos;
	int			size_a;
	int			size_b;

	size_a = lst_size(*a);
	size_b = lst_size(*b);
	max_b = get_greater(less_cost, max_b);
	pos = get_positions(a, b, less_cost, max_b);
	while ((!(size_a - pos.position_a) || !(size_b - pos.position_b))  && before_middle(
		size_a, pos.position_a) && before_middle(size_b, pos.position_b))
	{
		ft_rr(a, b);
		less_cost->cost--;
		pos.position_a++;
	}
	while ((!(size_a - pos.position_a) || !(size_b - pos.position_b)) && !before_middle(
		size_a, pos.position_a) && !before_middle(size_b, pos.position_b))
	{
		ft_rrr(a,b);
		less_cost->cost--;
		pos.position_b--;
	}	
	while (before_middle(size_a, pos.position_a) && *a != less_cost)
	{
		ft_rotate(a);
		less_cost->cost--;
		pos.position_a++;
	}
	while (before_middle(size_b, pos.position_b) && *b != max_b)
	{
		ft_rotate(b);
		less_cost->cost--;
		pos.position_b++;
	}
	while (!before_middle(size_a, pos.position_a) && *a != less_cost)
	{
		ft_reverse_rotate(a);
		less_cost->cost--;
		pos.position_a--;
	}
	while (!before_middle(size_b, pos.position_b) && *b != max_b)
	{
		ft_reverse_rotate(b);
		less_cost->cost--;
		pos.position_b--;
	}
	ft_push(a,b);
}

static t_positions	get_positions(t_stack **a, t_stack **b, 
	t_stack *less_cost, t_stack *max_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_positions	pos;

	pos.position_a = -1;
	pos.position_b = -1;
	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a && ++pos.position_a >= 0)
	{
		tmp_a = tmp_a->next;
		if (tmp_a == less_cost)
			break ;
	}
	while (tmp_b && ++pos.position_b >= 0)
	{
		tmp_b = tmp_b ->next;
		if (tmp_b == max_b)
			break ;
	}
	return pos;
}

static t_stack	*find_less_cost(t_stack **a)
{
	t_stack *tmp;
	t_stack *less_cost;

	less_cost = *a;
	tmp = *a;
	while (tmp)
	{
		tmp = tmp -> next;
		if (tmp->cost < less_cost->cost)
			less_cost = tmp;
		if (tmp == *a)
			break;
	}
	return (less_cost);
}

static void	fill_cost(t_stack **a, t_stack *max)
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
	int	dual_rotate;

	dual_rotate = 0;
	if ((!(size_a % 2) && cost1 >= size_a / 2) || (
		cost1 >= size_a / 2 + 1))
	{
		cost1 = size_a - cost1;
		dual_rotate++;
	}
	if (cost2 >= size_b)
		cost2 -= size_b;
	if ((!(size_b % 2) && cost2 >= size_b / 2) || (
		cost2 >= size_b / 2 + 1))
		dual_rotate++;
	if (dual_rotate == 2 || dual_rotate == 0)
	{	
		if (cost1 == cost2)
			return (cost2 + 1);
		else
			return (ft_max(cost1, cost2) + 1);
	}
	// if (dual_rotate == 1 && (!(size_a % 2) || !(size_b % 2)))
	// 	return (ft_max(cost1, cost2) + 1);
	return (cost1 + cost2 + 1);
}

static t_stack	*lst_max_value(t_stack **stack)
{
	t_stack *tmp;
	t_stack *max;
	int		position;
	
	tmp =  (*stack);
	max = tmp;
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
