/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:54:12 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/26 17:02:32 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_if_both_above_mid(t_dnode **a, t_dnode **b, t_dnode *cheapest)
{
	while (cheapest != *a && cheapest->target != *b)
			rr(a, b);
		while (cheapest != *a)
			ra(a);
		while (cheapest->target != *b)
			rb(b);
}

void	rotate_if_both_below_mid(t_dnode **a, t_dnode **b, t_dnode *cheapest)
{
		while (cheapest != *a && cheapest->target != *b)
			rrr(a, b);
		while (cheapest != *a)
			rra(a);
		while (cheapest->target != *b)
			rrb(b);
}

void	rotate_seperate(t_dnode **a, t_dnode **b, t_dnode *cheapest, int size_a, int size_b)
{
	if (cheapest->index <= size_a / 2)
			while (cheapest != *a)
				ra(a);
		else
			while (cheapest != *a)
				rra(a);
		if (cheapest->target->index <= size_b / 2)
			while (cheapest->target != *b)
				rb(b);
		else
			while (cheapest->target != *b)
				rrb(b);
}
