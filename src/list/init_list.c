/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:06:22 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/26 16:50:29 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


t_dnode	*init_list(char **values)
{
	t_dnode *a;
	t_dnode *node;
	int		i;
	int		value;

	i = 0;
	a = NULL;
	while(values[i] != NULL)
	{
		value = ft_atoi_plus(values[i]);
		if (!a)
		{
			a = create_node(value, i);
			if (!a)
			{
				free_values(values);
				handle_error();
			}
		}
		else
		{
			node = create_node(value, i);
			if (!node)
			{
				free_values(values);
				free_list(&a);
				handle_error();
			}
			add_to_list_back(&a, node);
		}
		i ++;
	}
	return a;
}
void	set_list_index(t_dnode *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list->index = i;
		i++;
		list = list->next;
	}
}
void	set_nearest_smaller_target(t_dnode **a, t_dnode **b)
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
void	set_nearest_bigger_target(t_dnode **a, t_dnode **b)
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
