/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:37:22 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/25 17:29:45 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_list_index(t_dnode **list)
{
	int	i;

	i = 0;
	while (*list)
	{
		(*list)->index = i;
		i++;
		*list = (*list)->next;
	}
}

void	free_dlist(t_dnode **dlist)
{
	if (!dlist || !*dlist)
		return ;
	t_dnode *temp;
	while (*dlist)
	{
		temp = *dlist;
		*dlist = (*dlist)->next;
		free(temp);
	}
	*dlist = NULL;
}

t_dnode	*init_dlist(char **values)
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
			a = create_dnode(value, i);
			if (!a)
			{
				free_values(values);
				handle_error();
			}
		}
		else
		{
			node = create_dnode(value, i);
			if (!node)
			{
				free_values(values);
				free_dlist(&a);
				handle_error();
			}
			add_back_dlist(&a, node);
		}
		i ++;
	}
	// a->size = i;
	// a->mid = i / 2;
	return a;
}

t_dnode	*create_dnode(int value, int index)
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
void	push_dlist(t_dnode **head, t_dnode *node)
{
	if (!node)
		return ;
	if (!(*head))
	{
		node->prev = NULL;
		*head = node;
		return ;
	}
	node->next = *head;
	(*head)->prev = node;
	(*head) = node;
	node->prev = NULL;
}
t_dnode *pop_dlist(t_dnode **head)
{
	t_dnode *node;

	if (!head || !*head)
		return (NULL);
	node = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	node->next = NULL;
	return (node);
}

t_dnode	*get_dlist_last(t_dnode *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	add_back_dlist(t_dnode **head, t_dnode *new_node)
{
	t_dnode	*last;

	if (!*head)
		*head = new_node;
	else
	{
		last = get_dlist_last(*head);
		last->next = new_node;
		new_node->prev = last;
	}
}
// counts size and sets index for each node
int	get_dlist_size(t_dnode *head)
{
	int		size;

	size = 0;
	while (head)
	{
		head->index = size;
		head = head->next;
		size ++;
	}
	return (size);
}

void	print_dlist(t_dnode *a, t_dnode *b)
{
	int	i;
	int	max;
	int	size_a;
	int	size_b;

	size_a = get_dlist_size(a);
	size_b = get_dlist_size(b);
	i = 0;
	if (size_a <= size_b)
		max = size_b;
	else 
		max = size_a;
	while (i < max)
	{
		if (i < size_a)
		{
			ft_printf("%d", a->value);
			a = a->next;
		}
		else 
			ft_printf("x");
		ft_printf("\t");
		if (i < size_b)
		{
			ft_printf("%d", b->value);
			b = b->next;
		}
		else 
			ft_printf("x");
		ft_printf("\t");
		i ++;
		ft_printf("\n");
	}
	ft_printf("_\t_\n");
	ft_printf("a\tb\n");
}

void print_node(t_dnode *node)
{
	if (!node)
	{
		printf("Node is NULL\n");
		return;
	}
	printf("===== Node Details =====\n");
	printf("Value: %d\n", node->value);
	printf("Index: %d\n", node->index);
	printf("Cost: %d\n", node->cost);

	if (node->target)
		printf("Target: [Value: %d, Index: %d]\n", node->target->value, node->target->index);
	else
		printf("Target: NULL\n");
	printf("========================\n");
}
