/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:50:18 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/22 17:03:37 by phhofman         ###   ########.fr       */
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