/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:37:22 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/26 11:12:01 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_list(t_dnode *a, t_dnode *b)
{
	int	i;
	int	max;
	int	size_a;
	int	size_b;

	size_a = get_list_size(a);
	size_b = get_list_size(b);
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
