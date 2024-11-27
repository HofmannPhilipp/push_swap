/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:08:37 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/27 13:26:25 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_dnode	*create_node(int value, int index)
{
	t_dnode	*node;

	node = (t_dnode *)malloc(sizeof(t_dnode));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
void	push(t_dnode **list, t_dnode *node)
{
	if (!node)
		return ;
	if (!(*list))
	{
		node->prev = NULL;
		node->next = NULL;
		*list = node;
		return ;
	}
	node->next = *list;
	(*list)->prev = node;
	(*list) = node;
	node->prev = NULL;
}
t_dnode *pop(t_dnode **list)
{
	t_dnode *node;

	if (!list || !*list)
		return (NULL);
	node = *list;
	*list = (*list)->next;
	if (*list)
		(*list)->prev = NULL;
	node->next = NULL;
	node->target = NULL;
	return (node);
}

void	add_to_list_back(t_dnode **list, t_dnode *new_node)
{
	t_dnode	*last;

	if (!*list)
		*list = new_node;
	else
	{
		last = get_last_node(*list);
		last->next = new_node;
		new_node->prev = last;
	}
}