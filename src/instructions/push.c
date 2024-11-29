/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:52:17 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/29 08:43:50 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_dnode **a, t_dnode **b)
{
	t_dnode	*node;

	if (!*b)
		return ;
	ft_printf("pa\n");
	node = pop(b);
	push(a, node);
	set_list_index(*a);
	set_list_index(*b);
}

void	pb(t_dnode **a, t_dnode **b)
{
	t_dnode	*node;

	if (!*a)
		return ;
	ft_printf("pb\n");
	node = pop(a);
	push(b, node);
	set_list_index(*a);
	set_list_index(*b);
}
