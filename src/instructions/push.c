/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:52:17 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/27 09:50:46 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_dnode **a, t_dnode **b)
{
	if (!*b)
		return ;
	ft_printf("pa\n");
	t_dnode *node;

	node = pop(b);
	push(a, node);
	set_list_index(*a);
	set_list_index(*b);
}

void	pb(t_dnode **a, t_dnode **b)
{
	if (!*a)
		return ;
	ft_printf("pb\n");
	t_dnode *node;

	node = pop(a);
	push(b, node);
	set_list_index(*a);
	set_list_index(*b);
}