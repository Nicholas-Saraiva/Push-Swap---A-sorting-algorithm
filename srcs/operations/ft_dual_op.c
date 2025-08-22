/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dual_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:01:41 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/22 11:59:07 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	ft_printf("rr\n");
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a, 0);
	ft_reverse_rotate(b, 0);
	ft_printf("rrr\n");
}
