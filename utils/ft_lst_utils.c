#include "push_swap.h"

t_stack	*lstnew(int *content)
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
	tmp = head -> next;
	while (tmp && tmp != head)
	{
		if (tmp -> content[0] == number)
			return (0);
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
        free(actual_pos->content);
        free(actual_pos);
        actual_pos = tmp;
		if (actual_pos == head)
			break;
    }
    *lst = NULL;
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
	if (!*lst && new)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	new -> next = *lst;
	(*lst) -> previus = new;
	*lst = new;
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*next_node;
	t_stack *first_pos;
	int		i;

	i = 0;
	next_node = *lst;
	first_pos = *lst;
	if (!*lst && new)
	{
		new->position = i;
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	while (++i && next_node -> next != first_pos && next_node -> next)
		next_node = next_node -> next;
	new -> next = first_pos;
	new -> previus = next_node;
	new -> position = i;
	next_node -> next = new;
	first_pos->previus = new;
}
