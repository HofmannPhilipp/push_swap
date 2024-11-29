/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:37:22 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/29 09:06:19 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_node(t_dnode *node)
{
	if (!node)
	{
		ft_printf("Node is NULL\n");
		return ;
	}
	ft_printf("===== Node Details =====\n");
	ft_printf("Value: %d\n", node->value);
	ft_printf("Index: %d\n", node->index);
	ft_printf("Cost: %d\n", node->cost);
	if (node->target)
		ft_printf("Target: [Value: %d, Index: %d]\n", \
		node->target->value, node->target->index);
	else
		ft_printf("Target: NULL\n");
	ft_printf("========================\n");
}

// void	print_list(t_dnode *a, t_dnode *b)
// {
// 	int	i;
// 	int	max;
// 	int	size_a;
// 	int	size_b;

// 	size_a = get_list_size(a);
// 	size_b = get_list_size(b);
// 	i = 0;
// 	if (size_a <= size_b)
// 		max = size_b;
// 	else 
// 		max = size_a;
// 	while (i < max)
// 	{
// 		if (i < size_a)
// 		{
// 			ft_printf("%d", a->value);
// 			a = a->next;
// 		}
// 		else 
// 			ft_printf("x");
// 		ft_printf("\t");
// 		if (i < size_b)
// 		{
// 			ft_printf("%d", b->value);
// 			b = b->next;
// 		}
// 		else
// 			ft_printf("x");
// 		ft_printf("\t");
// 		i ++;
// 		ft_printf("\n");
// 	}
// 	ft_printf("_\t_\n");
// 	ft_printf("a\tb\n");
// }