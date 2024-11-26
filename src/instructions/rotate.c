/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:53:13 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/26 10:53:45 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_dnode **a)
{
	if (!*a || !(*a)->next)
		return ;
	ft_printf("ra\n");
	
	t_dnode *first;
	t_dnode *last;

	first = *a;
	last = get_last_node(*a);
	last->next = first;
	*a = (*a)->next;
	first->prev = last;
	first->next = NULL;
}
void	rb(t_dnode **b)
{
	if (!*b || !(*b)->next)
		return ;
	ft_printf("rb\n");
	
	t_dnode *first;
	t_dnode *last;

	first = *b;
	last = get_last_node(*b);
	last->next = first;
	*b = (*b)->next;
	first->prev = last;
	first->next = NULL;
}

void	rr(t_dnode **a, t_dnode **b)
{
	ra(a);
	rb(b);
}
