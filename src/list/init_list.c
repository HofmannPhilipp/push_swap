/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:06:22 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/26 14:28:32 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
