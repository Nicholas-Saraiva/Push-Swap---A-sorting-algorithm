/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_lst_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:46:59 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/22 12:15:06 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_max_value(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*max;
	int		position;

	tmp = (*stack);
	max = tmp;
	max->cost = 0;
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

int	check_lstrepetition(t_stack **lst, int number)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!*lst)
		return (1);
	head = *lst;
	tmp = head;
	while (tmp)
	{
		if (tmp->content == number)
			return (0);
		if (tmp->next == NULL || tmp->next == head)
			break ;
		tmp = tmp->next;
	}
	return (1);
}
