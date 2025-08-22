/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:00:49 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/22 12:15:25 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack **a, t_stack **b)
{
	if (a)
		lstclear(a);
	if (b)
		lstclear(b);
	write(2, "Error\n", 6);
	exit(-1);
}

void	free_char_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		if (array[i])
			free(array[i]);
	if (array)
		free(array);
}
