/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:50:22 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/15 16:45:46 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **head)
{
	t_stack	*old_head;
	t_stack *tail;
	t_stack *next;
	t_stack *tmp;

	if (!*head || (*head)-> next == NULL || (*head) -> previus == NULL)
		return ;
	old_head = *head;
	tail = (*head) -> previus;
	next = (*head) -> next;
	(*head) = next;
	tmp = (*head) -> next;
 	tail -> next = (*head);
	(*head) -> previus = tail;
	old_head -> next = tmp;
	tmp -> previus = old_head;
	(*head) -> next = old_head;
	old_head ->previus = (*head);
}

void ft_rotate(t_stack **head)
{
	if (!*head || (*head) -> next == NULL || (*head) -> previus == NULL)
		return ;
	*head = (*head) -> next;
}

void ft_reverse_rotate(t_stack **head)
{
	if (!*head || (*head) -> next == NULL || (*head) -> previus == NULL)
		return ;
	*head = (*head) -> previus;
}

void	ft_push(t_stack **head1, t_stack **head2)
{
	t_stack	*old_head;
	t_stack	*previus;
	t_stack	*next;

	if (!*head1 || (*head1) -> next == NULL || (*head1) -> previus == NULL)
		return ;
	old_head = *head1;
	previus = old_head -> previus;
	next = old_head ->next;
	previus -> next = (*head1) -> next;
	next -> previus = (*head1) -> previus;
	(*head1) = (*head1) -> next;
	old_head -> next = NULL;
	old_head -> previus = NULL;
	lstadd_front(head2, old_head);
}

