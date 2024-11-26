/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:50:18 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/26 10:45:37 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_dnode **dlist)
{
	t_dnode *max;

	max = get_max_node(*dlist);
	if (max->index == 0)
		ra(dlist);
	else if (max->index == 1)
		rra(dlist);
	if (!is_sorted(*dlist))
		sa(*dlist);
}

void	set_target_node_min(t_dnode **a, t_dnode **b)
{
	t_dnode	*min;
	t_dnode	*curr_a;
	t_dnode *curr_b;

	curr_a = *a;
	while(curr_a)
	{
		curr_b = *b;
		min = curr_b;
		while (curr_b)
		{

			if (curr_b->value < curr_a->value && min->value < curr_b->value)
				min = curr_b;
			curr_b = curr_b->next;
		}
		if (min->value > curr_a->value)
			curr_a->target = get_max_node(*b);
		else
			curr_a->target = min;
		curr_a = curr_a->next;
	}
}
void	set_target_node_max(t_dnode **a, t_dnode **b)
{
	t_dnode	*max;
	t_dnode	*curr_a;

	curr_a = *a;
	max = (*b);
	while(curr_a)
	{
		if (curr_a->value > (*b)->value && max->value < curr_a->value)
			max = curr_a;

		curr_a = curr_a->next;
	}
	if (max->value == (*b)->value)
		max = get_min_node(*a);
	(*b)->target = max;
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
t_dnode	*get_cheapest_node(t_dnode *list)
{
	t_dnode *cheapest;

	cheapest = list;
	while (list)
	{
		if (list->cost < cheapest->cost)
			cheapest = list;
		list = list->next;
	}
	return (cheapest);
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
	{
		while (cheapest != *a && cheapest->target != *b)
			rr(a, b);
		while (cheapest != *a)
			ra(a);
		while (cheapest->target != *b)
			rb(b);
	}
	else if (cheapest->index > size_a / 2 && cheapest->target->index > size_b / 2)
	{
		while (cheapest != *a && cheapest->target != *b)
			rrr(a, b);
		while (cheapest != *a)
			rra(a);
		while (cheapest->target != *b)
			rrb(b);
	}
	else
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
}

void	move_from_b_to_a(t_dnode **a, t_dnode **b)
{
	int	size_a;

	size_a = get_list_size(*a);
	if ((*b)->target->index <= size_a / 2)
		while ((*b)->target != *a)
			ra(a);
	else 
		while ((*b)->target != *a)
			rra(a);
	pa(a, b);
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
		set_list_index(*a);
		set_list_index(*b);
		set_target_node_min(a, b);
		move_from_a_to_b(a, b);
		pb(a, b);
	}
	// set_list_index(*a);
	set_list_index(*b);
	sort_three(a);
	set_list_index(*a);
	// set_target_node_max(a, b);
	// while (*b != NULL)
	// {
	// 	set_list_index(*a);
	// 	set_list_index(*b);
		
	// 	move_from_b_to_a(a, b);
	// }
}
