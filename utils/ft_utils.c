/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:05:50 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/13 18:05:52 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "push_swap.h"

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

long	ft_break_atoi(const char *split)
{
	int			i;
	long		number;

	i = -1;
	number = 0;
	while (split[++i] && (number >= INT_MIN || number <= INT_MAX))
	{
		if (split[i] < '0'  || split[i] > '9')
			return (0);
		number = split[i] - '0' + number * 10;
	}
	return (number);
}
