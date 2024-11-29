/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:06:22 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/29 08:58:46 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_dnode	*init_list(char **values)
{
	t_dnode	*list;
	t_dnode	*node;
	int		i;
	int		value;

	i = 0;
	list = NULL;
	while (values[i] != NULL)
	{
		value = ft_atoi_plus(values[i]);
		node = create_node(value, i);
		if (!node)
		{
			free_values(values);
			free_list(&list);
			handle_error();
		}
		add_to_list_back(&list, node);
		i ++;
	}
	return (list);
}

void	set_list_index(t_dnode *list)
{
	int	i;

	if (!list)
		return ;
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
	t_dnode	*nearest_smaller;
	t_dnode	*curr_a;
	t_dnode	*curr_b;

	curr_a = *a;
	while (curr_a)
	{
		curr_b = *b;
		nearest_smaller = NULL;
		while (curr_b)
		{
			if (curr_b->value < curr_a->value && \
			(!nearest_smaller || curr_b->value > nearest_smaller->value))
				nearest_smaller = curr_b;
			curr_b = curr_b->next;
		}
		if (!nearest_smaller)
			nearest_smaller = get_max_node(*b);
		curr_a->target = nearest_smaller;
		curr_a = curr_a->next;
	}
}

void	set_nearest_bigger_target(t_dnode **a, t_dnode **b)
{
	t_dnode	*nearest_bigger;
	t_dnode	*curr_a;

	curr_a = *a;
	nearest_bigger = NULL;
	while (curr_a)
	{
		if (curr_a->value > (*b)->value && \
		(!nearest_bigger || curr_a->value < nearest_bigger->value))
			nearest_bigger = curr_a;
		curr_a = curr_a->next;
	}
	if (!nearest_bigger)
		nearest_bigger = get_min_node(*a);
	(*b)->target = nearest_bigger;
}
