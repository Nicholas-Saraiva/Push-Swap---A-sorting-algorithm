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

int	check_lstrepetition(t_stack **lst, int number)
{
	t_stack *tmp;
	t_stack *head;

	if (!*lst)
		return (1);
	head = *lst;
	tmp = head;
	while (tmp)
	{
		if (tmp -> content == number)
			return (0);
		if (tmp -> next == NULL || tmp -> next == head)
			break ;
		tmp = tmp -> next;
	}
	return (1);
}

void lstclear(t_stack **lst)
{
    t_stack *actual_pos;
    t_stack *tmp;
	t_stack	*head;

    if (!lst || !*lst)
        return;
    actual_pos = *lst;
	head = actual_pos;
    while (actual_pos != NULL)
    {
        tmp = actual_pos->next;
        free(actual_pos);
        actual_pos = tmp;
		if (actual_pos == head)
			break;
    }
    *lst = NULL;
}

void	lstadd_front(t_stack **lst, t_stack *new_head)
{
	t_stack	*old_head;
	t_stack *previus;

	if (!*lst && new_head)
	{
		*lst = new_head;
		return ;
	}
	if (!new_head)
		return ;
	previus = (*lst) -> previus;
	old_head = (*lst);
	new_head -> next = old_head;
	new_head -> previus = previus;
	(*lst) = new_head;
	previus -> next = new_head;
	old_head -> previus = new_head;
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*next_node;
	t_stack *first_pos;

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
