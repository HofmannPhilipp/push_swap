/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:52:17 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/26 17:16:00 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_dnode **a, t_dnode **b)
{
	if (!*b || !(*b)->next)
		return ;
	ft_printf("pa\n");
	t_dnode *node;

	node = pop(b);
	push(a, node);
}

void	pb(t_dnode **a, t_dnode **b)
{
	if (!*a || !(*a)->next)
		return ;
	ft_printf("pb\n");
	t_dnode *node;

	node = pop(a);
	push(b, node);
}