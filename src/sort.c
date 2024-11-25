/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:50:18 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/25 10:38:05 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dnode	*cmp(t_dnode *a, t_dnode *b)
{
	if ((a->value) > (b->value))
		return (a);
	return (b);
}
void	sort_three(t_dnode **dlist)
{
	t_dnode *max;

	max = get_max(*dlist);
	if (max->index == 0)
		ra(dlist);
	else if (max->index == 1)
		rra(dlist);
	if (!is_sorted(*dlist))
		sa(*dlist);
}


t_dnode	*get_max(t_dnode *dlist)
{
	t_dnode	*max;

	max = dlist;
	while (dlist)
	{
		max = cmp(max, dlist);
		dlist = dlist->next;
	}
	return (max);
}

t_dnode	*get_min(t_dnode *dlist)
{
	t_dnode	*min;

	min = dlist;
	while (dlist)
	{
		if (min->value > dlist->value)
			min = dlist;
		dlist = dlist->next;
	}
	return (min);
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
		if (min > curr_a->value)
			curr_a->target = get_max(*b);
		else
			curr_a->target = min;
		ft_printf("v:%d	t:%d\n", curr_a->value, curr_a->target->value);
		curr_a = curr_a->next;
	}
}

int	calc_cheapest(t_dnode *a, t_dnode *b)
{
	int	min;

	
}

// void	turk_sort(t_dnode **a, t_dnode **b)
// {
// 	while (!is_sorted(*a))
// 	{
// 		if(get_dlist_size(*a) == 3)
// 		{
// 			sort_three(a);
// 			if (get_dlist_size(*b) > 0)
// 			{
// 				calc_cheapest(*a, *b);
// 			}
// 		}
// 		pb(a, b);

// 	}
// }


// void	radix_sort(t_dnode **a, t_dnode **b)
// {
// 	int		max;
// 	t_dnode	*curr;
// 	int	i;
// 	int	target;
	
// 	max = get_max(*a, &cmp)->value;
// 	i = 1;
	
// 	while (max / i > 0)
// 	{
// 		curr = *a;
// 		while (curr)
// 		{
// 			target = curr->value / i;

// 			if (target == 0)
// 			curr = curr->next;
// 		}

// 		i *= 10;
// 	}

// }