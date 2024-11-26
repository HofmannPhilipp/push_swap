/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:27:59 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/26 10:54:41 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_dnode **a)
{
	if (!*a || !(*a)->next)
		return ;
	ft_printf("rra\n");
	
	t_dnode *last;

	last = get_last_node(*a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *a;
	*a = last;
}

void	rrb(t_dnode **b)
{
	if (!*b || !(*b)->next)
		return ;
	ft_printf("rrb\n");
	
	t_dnode *last;

	last = get_last_node(*b);
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *b;
	*b = last;
}

void rrr(t_dnode **a, t_dnode **b)
{
	rra(a);
	rrb(b);
}
