/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:50:18 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/27 14:30:36 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_dnode **dlist)
{
	t_dnode *max;

	max = get_max_node(*dlist);
	if (max->index == 0)
		ra(dlist, 1);
	else if (max->index == 1)
		rra(dlist, 1);
	if (!is_sorted(*dlist))
		sa(*dlist);
}

void	calc_cheapest(t_dnode *a, t_dnode *b)
{
	int	size_a;
	int	size_b;

	size_a = get_list_size(a);
	size_b = get_list_size(b);
	while (a)
	{
		if (a->index <= size_a / 2)
			a->cost = a->index;
		else
			a->cost = size_a - a->index;
		if (a->target->index <= size_b / 2)
			a->cost += a->target->index;
		else
			a->cost += size_b - a->target->index;
		a = a->next;
	}
}

void	move_from_a_to_b(t_dnode **a, t_dnode **b)
{
	int	size_a;
	int	size_b;
	t_dnode	*cheapest;

	size_a = get_list_size(*a);
	size_b = get_list_size(*b);
	calc_cheapest(*a, *b);
	cheapest = get_cheapest_node(*a);

	if (cheapest->index <= size_a / 2 && cheapest->target->index <= size_b / 2)
		rotate_if_both_above_mid(a, b, cheapest);
	else if (cheapest->index > size_a / 2 && cheapest->target->index > size_b / 2)
		rotate_if_both_below_mid(a, b, cheapest);
	else
		rotate_seperate(a, b, cheapest, size_a, size_b);
}

void	move_from_b_to_a(t_dnode **a, t_dnode **b)
{
	int	size_a;

	size_a = get_list_size(*a);
	if ((*b)->target->index <= size_a / 2)
		while ((*b)->target != *a)
			ra(a, 1);
	else 
		while ((*b)->target != *a)
			rra(a, 1);
	pa(a, b);
}

void	move_min_to_top(t_dnode **a)
{
	int	size_a;
	t_dnode *min;

	size_a = get_list_size(*a);
	min = get_min_node(*a);
	if (min->index <= size_a / 2)
		while (min->index != 0)
			ra(a, 1);
	else 
		while (min->index != 0)
			rra(a, 1);
}

void	turk_sort(t_dnode **a, t_dnode **b)
{

	if (!is_sorted(*a) && get_list_size(*a) == 2)
		return sa(*a);
	if (!is_sorted(*a) && get_list_size(*a) > 3)
		pb(a, b);
	if (!is_sorted(*a) && get_list_size(*a) > 3)
		pb(a, b);
	while (!is_sorted(*a) && get_list_size(*a) > 3)
	{
		set_nearest_smaller_target(a, b);
		move_from_a_to_b(a, b);
		pb(a, b);
	}
	sort_three(a);
	while (*b != NULL)
	{
		set_nearest_bigger_target(a, b);
		move_from_b_to_a(a, b);
	}
	if (!is_sorted(*a))
		move_min_to_top(a);
}
