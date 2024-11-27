/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:27:59 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/27 14:27:16 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_dnode **a, int print)
{
	if (!*a || !(*a)->next)
		return ;
	if(print == 1)
		ft_printf("rra\n");
	
	t_dnode *last;

	last = get_last_node(*a);
	last->prev->next = NULL;
	last->next = *a;
	last->prev = NULL;
	*a = last;
	last->next->prev = last;
	set_list_index(*a);
}

void	rrb(t_dnode **b, int print)
{
	if (!*b || !(*b)->next)
		return ;
	if(print == 1)
		ft_printf("rrb\n");
	
	t_dnode *last;

	last = get_last_node(*b);
	if (last->prev)
		last->prev->next = NULL;
	last->next = *b;
	last->prev = NULL;
	*b = last;
	last->next->prev = last;
	set_list_index(*b);
}

void rrr(t_dnode **a, t_dnode **b, int print)
{
	if(print == 1)
		ft_printf("rrr\n");
	rra(a, 0);
	rrb(b, 0);
}
