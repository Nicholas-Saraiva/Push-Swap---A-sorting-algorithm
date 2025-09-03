/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:50:22 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/09/03 18:16:25 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_one_elem(t_stack **head1, t_stack **head2, char c);

void	ft_swap(t_stack **head, char c)
{
	t_stack	*old_head;


	if (!*head || (*head)->next == NULL || (*head)->previus == NULL)
		return ;
	old_head = *head;
	(*head) = (*head)->next;
	if (old_head->previus != old_head->next)
	{
		(*head)->next->previus = old_head;
		old_head->next = (*head)->next->previus;
		(*head)->next = old_head;
		(*head)->previus = old_head->previus;
		old_head->previus = (*head);
	}
	if (c)
		ft_printf("s%c\n", c);
}

// void	ft_swap(t_stack **head, char c)
// {
// 	t_stack	*old_head;
// 	t_stack	*tail;
// 	t_stack	*next;
// 	t_stack	*tmp;

// 	if (!*head || (*head)->next == NULL || (*head)->previus == NULL)
// 		return ;
// 	old_head = *head;
// 	tail = (*head)->previus;
// 	next = (*head)->next;
// 	(*head) = next;
// 	tmp = (*head)->next;
// 	tail->next = (*head);
// 	(*head)->previus = tail;
// 	old_head->next = tmp;
// 	tmp->previus = old_head;
// 	(*head)->next = old_head;
// 	old_head->previus = (*head);
// 	if (c)
// 		ft_printf("s%c\n", c);
// }

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
