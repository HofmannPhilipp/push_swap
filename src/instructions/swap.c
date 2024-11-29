/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:51:03 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/29 08:48:11 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_dnode *a)
{
	int	temp;

	if (!a || !a->next)
		return ;
	ft_printf("sa\n");
	temp = a->value;
	a->value = a->next->value;
	a->next->value = temp;
	set_list_index(a);
}

void	sb(t_dnode *b)
{
	int	temp;

	if (!b || !b->next)
		return ;
	ft_printf("sa\n");
	temp = b->value;
	b->value = b->next->value;
	b->next->value = temp;
	set_list_index(b);
}

void	ss(t_dnode *a, t_dnode *b)
{
	sa(a);
	sb(b);
}
