/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:04:58 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/29 08:59:58 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_dnode	*get_max_node(t_dnode *list)
{
	t_dnode	*max;

	max = list;
	while (list)
	{
		if (max->value < list->value)
			max = list;
		list = list->next;
	}
	return (max);
}

t_dnode	*get_min_node(t_dnode *dlist)
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

int	get_list_size(t_dnode *list)
{
	int		size;

	size = 0;
	while (list)
	{
		list = list->next;
		size ++;
	}
	return (size);
}

t_dnode	*get_last_node(t_dnode *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

t_dnode	*get_cheapest_node(t_dnode *list)
{
	t_dnode	*cheapest;

	cheapest = list;
	while (list)
	{
		if (list->cost < cheapest->cost)
			cheapest = list;
		if (cheapest->cost == 0)
			return (cheapest);
		list = list->next;
	}
	return (cheapest);
}
