/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:53:13 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/27 14:28:26 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_dnode **a, int print)
{
	if (!*a || !(*a)->next)
		return ;
	
	t_dnode *first;
	t_dnode *last;

	if (print == 1)
		ft_printf("ra\n");
	first = *a;
	last = get_last_node(*a);
	last->next = first;
	*a = (*a)->next;
	first->prev = last;
	first->next = NULL;
	set_list_index(*a);
}
void	rb(t_dnode **b, int print)
{
	if (!*b || !(*b)->next)
		return ;
	
	t_dnode *first;
	t_dnode *last;
	if (print == 1)
		ft_printf("rb\n");
	first = *b;
	last = get_last_node(*b);
	last->next = first;
	*b = (*b)->next;
	first->prev = last;
	first->next = NULL;
	set_list_index(*b);
}

void	rr(t_dnode **a, t_dnode **b, int print)
{
	if (print == 1)
		ft_printf("rr\n");
	ra(a, 0);
	rb(b, 0);
}
