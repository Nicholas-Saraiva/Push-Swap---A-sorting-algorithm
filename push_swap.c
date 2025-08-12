/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:30:46 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/11 17:33:47 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	get_size(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		i++;
	return (i);
}

int *new_value(int value)
{
	int	*new_value;

	new_value = malloc(sizeof(int));
	if (!new_value)
		return (0);
	new_value[0] = value;
	return (new_value);
}

void	fill_stack(char *split, t_stack **a)
{
	int	i;
	int	number;
	int *value;
	t_stack *new;

	i = -1;
	number = 0;
	while (split[++i])
	{
		if (split[i] < '0'  || split[i] > '9')
			return ((void) 0);
		number = split[i] - '0' + number * 10;
	}
	value = new_value(number);
	new = lstnew(value);
	lstadd_front(a, new);
	if (!a)
		return ((void) 0);
	
}

void	make_stack(int argc, char **argv, t_stack **a)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = -1;
		while (split[++j])
		{
			fill_stack(split[j], a);
			if (!a)
				return (0);
			free(split[j]);
		}
		free(split);
	}
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	//int	dupli[INT_MAX]};
	t_stack *a;

	a = NULL;
	if (argc < 2)
		return (0);
	make_stack(argc, argv, &a);
	if (!a)
		return (0);
	lstclear(&a);
	if (argv[0])
		return (0);
	return (0);
}
