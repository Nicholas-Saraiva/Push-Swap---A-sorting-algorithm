/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:30:46 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/15 16:46:08 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_stack(char *split, t_stack **a);
static int	make_stack(int argc, char **argv, t_stack **a);

int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	t_stack *first;

	a = NULL;
	b = NULL;
	if (argc < 2 || !make_stack(argc, argv, &a))
		return (0);
	ft_tiny_sort(&a);
	turk_sort(&a, &b);
	//ft_reverse_rotate(&a);
	first = a;
	while (a->next != first)
	{
		ft_printf("Number: %d				Cost: %d\n", a->content, a->cost);
		a = a->next;
	}
		ft_printf("%d\n", a->content);
	if (argv[0])
		return (0);
	return (0);
}

static int	make_stack(int argc, char **argv, t_stack **a)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (i != 1 && j != 1)
			return (free_char_array(split), ft_error(a, (t_stack **) NULL), 0);
		j = -1;
		while (split[++j])
			if (!fill_stack(split[j], a))
				return (free_char_array(split), ft_error(a, (t_stack **) NULL), 0);
		if (i > 1 && j != 1)
				return (free_char_array(split), ft_error(a, (t_stack **) NULL), 0);
		free_char_array(split);
	}
	return (1);
}

static int	fill_stack(char *split, t_stack **a)
{
	int			number;
	t_stack 	*new;

	number = 0;
	if (!ft_strtoi(split, &number))
		return (0);
	if (!check_lstrepetition(a, number))
		return (0);
	new = lstnew(number);
	lstadd_back(a, new);
	if (!a)
		return (0);
	return (1);
}
