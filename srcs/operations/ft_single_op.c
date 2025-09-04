/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:50:22 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/04 14:33:58 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_one_elem(t_stack **head1, t_stack **head2, char c);

void	ft_swap(t_stack **head, char c)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!*head || !((*head)->next))
		return ;
	if ((*head)->next == (*head)->previus)
	{
		*head = (*head)->next;
		return ;
	}
	first = *head;
	second = first->next;
	last = first->previus;
	first->next = second->next;
	second->next->previus = first;
	second->previus = last;
	second->next = first;
	first->previus = second;
	last->next = second;
	*head = second;
	if (c)
		ft_printf("s%c\n", c);
}

void	ft_rotate(t_stack **head, char c)
{
	if (!*head || (*head)->next == NULL || (*head)->previus == NULL)
		return ;
	*head = (*head)->next;
	if (c)
		ft_printf("r%c\n", c);
}

void	ft_reverse_rotate(t_stack **head, char c)
{
	if (!*head || (*head)->next == NULL || (*head)->previus == NULL)
		return ;
	*head = (*head)->previus;
	if (c)
		ft_printf("rr%c\n", c);
}

void	ft_push(t_stack **head1, t_stack **head2, char c)
{
	t_stack	*old_head;
	t_stack	*previus;
	t_stack	*next;

	if (is_one_elem(head1, head2, c))
		return ;
	old_head = *head1;
	previus = old_head->previus;
	next = old_head ->next;
	previus->next = (*head1)->next;
	next->previus = (*head1)->previus;
	(*head1) = (*head1)->next;
	old_head->next = NULL;
	old_head->previus = NULL;
	if (previus == next)
	{
		(*head1)->next = NULL;
		(*head1)->previus = NULL;
	}
	lstadd_front(head2, old_head);
	if (c)
		ft_printf("p%c\n", c);
}

static int	is_one_elem(t_stack **head1, t_stack **head2, char c)
{
	if (!*head1)
		return (1);
	if ((*head1)->next == NULL)
	{
		lstadd_front(head2, (*head1));
		(*head1) = NULL;
		if (c)
			ft_printf("p%c\n", c);
		return (1);
	}
	return (0);
}
