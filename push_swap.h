/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:32:39 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/11 17:30:34 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct	s_stack
{
	int	*content;
	int	position;
	void	*next;
	void	*previus;
}	t_stack;

//--------------Utils
t_stack	*lstnew(int *content);
void	lstdelone(t_stack *lst, void (*del)(void *));
void	lstclear(t_stack **lst);
void	lstadd_front(t_stack **lst, t_stack *new);

#endif
