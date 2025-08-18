/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dual_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:01:41 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/17 10:01:43 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_ss(t_stack **a, t_stack **b)
{
    ft_swap(a);
    ft_swap(b);
}

void    ft_rr(t_stack **a, t_stack **b)
{
    ft_rotate(a);
    ft_rotate(b);
}

void    ft_rrr(t_stack **a, t_stack **b)
{
    ft_reverse_rotate(a);
    ft_reverse_rotate(b);
}