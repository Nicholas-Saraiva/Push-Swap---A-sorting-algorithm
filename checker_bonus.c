/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:58:26 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/04 14:50:34 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_stack(char *split, t_stack **a);
static int	make_stack(int argc, char **argv, t_stack **a);
static void	single_operation(t_stack **a, t_stack **b, char *buff);
static void	ft_error_bonus(t_stack **a, t_stack **b, char *buff, int error);

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*buff;

	a = NULL;
	b = NULL;
	buff = 0;
	if (argc < 2)
		return (0);
	if (!make_stack(argc, argv, &a))
		ft_error(&a, &b);
	while (get_next_line(0, &buff))
	{
		if (ft_strlen(buff) > 4)
			ft_error_bonus(&a, &b, buff, 1);
		single_operation(&a, &b, buff);
		free(buff);
	}
	if (ft_is_sort(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_error_bonus(&a, &b, buff, 0);
	return (0);
}

static void	single_operation(t_stack **a, t_stack **b, char *buff)
{
	if (!ft_strncmp(buff, "ra\n", 3))
		ft_rotate(a, 0);
	else if (!ft_strncmp(buff, "rb\n", 3))
		ft_rotate(b, 0);
	else if (!ft_strncmp(buff, "rra\n", 4))
		ft_reverse_rotate(a, 0);
	else if (!ft_strncmp(buff, "rrb\n", 4))
		ft_reverse_rotate(b, 0);
	else if (!ft_strncmp(buff, "pa\n", 3))
		ft_push(b, a, 0);
	else if (!ft_strncmp(buff, "pb\n", 3))
		ft_push(a, b, 0);
	else if (!ft_strncmp(buff, "sa\n", 3))
		ft_swap(a, 0);
	else if (!ft_strncmp(buff, "sb\n", 3))
		ft_swap(b, 0);
	else if (!ft_strncmp(buff, "rr\n", 3))
		ft_rr(a, b, 0);
	else if (!ft_strncmp(buff, "rrr\n", 4))
		ft_rrr(a, b, 0);
	else if (!ft_strncmp(buff, "ss\n", 3))
		ft_ss(a, b, 0);
	else
		ft_error_bonus(a, b, buff, 1);
}

static void	ft_error_bonus(t_stack **a, t_stack **b, char *buff, int error)
{
	if (a)
		lstclear(a);
	if (b)
		lstclear(b);
	if (buff)
		free(buff);
	if (error)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
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
				return (free_char_array(split), ft_error(
						a, (t_stack **) NULL), 0);
		if (i > 1 && j != 1)
			return (free_char_array(split), ft_error(
					a, (t_stack **) NULL), 0);
		free_char_array(split);
	}
	if (!(*a))
		return (0);
	return (1);
}

static int	fill_stack(char *split, t_stack **a)
{
	int			number;
	t_stack		*new;

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
