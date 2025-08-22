/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:05:50 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/22 13:14:47 by nsaraiva         ###   ########.fr       */
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

int	*new_value(int value)
{
	int	*new_value;

	new_value = malloc(sizeof(int));
	if (!new_value)
		return (0);
	new_value[0] = value;
	return (new_value);
}

int	ft_strtoi(const char *split, int *number)
{
	int		i;
	int		sign;
	long	new_number;

	i = -1;
	new_number = 0;
	sign = 1;
	if (*split == '+' || *split == '-')
	{
		if (*split == '-')
			sign = -1;
		if (!*(++split))
			return (0);
	}
	while (split[++i] && (new_number >= INT_MIN || new_number <= INT_MAX))
	{
		if (split[i] < '0' || split[i] > '9')
			return (0);
		new_number = split[i] - '0' + new_number * 10;
	}
	if ((new_number * sign < INT_MIN || new_number * sign > INT_MAX))
		return (0);
	*number = (int)(new_number * sign);
	return (1);
}

int	ft_max(const int a, const int b)
{
	if (a > b)
		return (a);
	return (b);
}
