/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:51:03 by phhofman          #+#    #+#             */
/*   Updated: 2024/12/02 17:53:51 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_dnode *a, int print)
{
	int	temp;

	if (!a || !a->next)
		return ;
	if (print == 1)
		ft_printf("sa\n");
	temp = a->value;
	a->value = a->next->value;
	a->next->value = temp;
	set_list_index(a);
}

void	sb(t_dnode *b, int print)
{
	int	temp;

	if (!b || !b->next)
		return ;
	if (print == 1)
		ft_printf("sb\n");
	temp = b->value;
	b->value = b->next->value;
	b->next->value = temp;
	set_list_index(b);
}

void	ss(t_dnode *a, t_dnode *b, int print)
{
	if (print == 1)
		ft_printf("ss\n");
	sa(a, 0);
	sb(b, 0);
}
