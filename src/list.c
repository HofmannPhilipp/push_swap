/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:37:22 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/20 10:51:57 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


t_dnode	*init_dlst(char **values)
{
	t_dnode *a;
	int		i;
	int		value;

	i = 0;
	a = NULL;
	while(values[i] != NULL)
	{
		value = ft_atoi(values[i]);
		if (!a)
			a = create_dnode(value);
		else
			add_back_dlst(&a, create_dnode(value));
		i ++;
	}
	return a;
}

t_dnode	*create_dnode(int value)
{
	t_dnode	*node;

	node = (t_dnode *)malloc(sizeof(t_dnode));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
void	push_dlst(t_dnode **head, t_dnode *node)
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
t_dnode *pop_dlst(t_dnode **head)
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

t_dnode	*get_dlst_last(t_dnode *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	add_back_dlst(t_dnode **head, t_dnode *new_node)
{
	t_dnode	*last;

	if (!*head)
		*head = new_node;
	else
	{
		last = get_dlst_last(*head);
		last->next = new_node;
		new_node->prev = last;
	}
}

int	get_dlst_size(t_dnode *head)
{
	int		size;

	size = 0;
	while (head)
	{
		head = head->next;
		size ++;
	}
	return (size);
}

void	print_dlst(t_dnode *a, t_dnode *b)
{
	int	i;
	int	max;
	int	size_a;
	int	size_b;

	size_a = get_dlst_size(a);
	size_b = get_dlst_size(b);
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