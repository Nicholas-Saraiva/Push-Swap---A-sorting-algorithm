/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:12:18 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/22 12:19:06 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int content)
{
	t_stack	*node;

	node = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (!node)
		return (0);
	node -> content = content;
	node -> next = NULL;
	node -> previus = NULL;
	return (node);
}

int	lst_size(t_stack *lst)
{
	t_stack	*head;
	int		i;

	i = 0;
	head = lst;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst -> next;
		i++;
		if (lst == head)
			return (i);
	}
	return (i);
}

void	lstclear(t_stack **lst)
{
	t_stack	*actual_pos;
	t_stack	*tmp;
	t_stack	*head;

	if (!lst || !*lst)
		return ;
	actual_pos = *lst;
	head = actual_pos;
	while (actual_pos != NULL)
	{
		tmp = actual_pos->next;
		free(actual_pos);
		actual_pos = tmp;
		if (actual_pos == head)
			break ;
	}
	*lst = NULL;
}

void	lstadd_front(t_stack **lst, t_stack *new_head)
{
	t_stack	*old_head;
	t_stack	*previus;

	if (!*lst && new_head)
	{
		*lst = new_head;
		return ;
	}
	if (!new_head)
		return ;
	previus = (*lst)->previus;
	if (!previus)
		previus = *lst;
	old_head = (*lst);
	new_head -> next = old_head;
	new_head -> previus = previus;
	(*lst) = new_head;
	if (previus)
		previus -> next = new_head;
	old_head -> previus = new_head;
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*next_node;
	t_stack	*first_pos;

	if (!*lst && new)
	{
		*lst = new;
		return ;
	}
	next_node = *lst;
	first_pos = *lst;
	if (!new)
		return ;
	while (next_node -> next != first_pos && next_node -> next)
		next_node = next_node -> next;
	new -> next = first_pos;
	new -> previus = next_node;
	next_node -> next = new;
	first_pos->previus = new;
}
