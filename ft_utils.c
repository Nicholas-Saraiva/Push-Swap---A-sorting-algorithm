#include "push_swap.h"

t_stack	*lstnew(int *content)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node -> content = content;
	node -> next = NULL;
	node -> previus = NULL;
	return (node);
}

void	lstdelone(t_stack *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}

void	lstclear(t_stack **lst)
{
	t_stack	*next;
	t_stack	*previus;

	if (!lst)
		return ;
	next = *lst;
	previus = next;
	while (next)
	{
		next = next -> next;
		free(previus -> content);
		free(previus);
		previus = next;
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

