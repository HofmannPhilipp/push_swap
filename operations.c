/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:27:59 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/19 17:51:08 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sa(t_dnode *a)
// {
// 	if (!a || !a->next)
// 		return ;
// 	int	*temp;
// 	ft_putstr_fd("sa\n", 1);
// 	temp = (int *)a->value;
// 	a->value = a->next->value;
// 	a->next->value = temp;
// }
// void	sb(t_dnode *b, int size)
// {
// 	if (size <= 1)
// 		return ;
// 	int	*temp;
// 	ft_putstr_fd("sb\n", 1);
// 	temp = (int *)b->value;
// 	b->value = b->next->value;
// 	b->next->value = temp;
// }

// void	ss(t_dnode *a, t_dnode *b, int size_a, int size_b)
// {
// 	sa(a);
// 	sb(b, size_b);
// }

// void	pa(t_dnode **a, t_dnode **b, int *size_a, int *size_b)
// {
// 	if (*size_b == 0)
// 		return ;
// 	ft_putstr_fd("pa\n", 1);
// 	t_dnode *node;

// 	node = *b;
// 	*b = (*b)->next;
// 	ft_lstadd_front(a, node);
// 	*size_a += 1;
// 	*size_b -= 1;
// }

// void	pb(t_dnode **a, t_dnode **b, int *size_a, int *size_b)
// {
// 	if (*size_a == 0)
// 		return ;
// 	ft_putstr_fd("pb\n", 1);
// 	t_dnode *node;

// 	node = *a;
// 	*a = (*a)->next;
// 	ft_lstadd_front(b, node);
// 	*size_b += 1;
// 	*size_a -= 1;
// }

// void	ra(t_dnode **a, int size_a)
// {
// 	if (size_a <= 1)
// 		return ;
// 	ft_putstr_fd("ra\n", 1);
	
// 	t_dnode *node_first;

// 	node_first = *a;
// 	ft_lstadd_back(a, node_first);
// 	*a = (*a)->next;
// 	node_first->next = NULL;
// }
// void	rb(t_dnode **b, int size_b)
// {
// 	if (size_b <= 1)
// 		return ;
// 	ft_putstr_fd("rb\n", 1);
// 	t_dnode *node_first;

// 	node_first = *b;
// 	ft_lstadd_back(b, node_first);
// 	*b = (*b)->next;
// 	node_first->next = NULL;
// }

// void	rr(t_dnode **a, t_dnode **b, int size_a, int size_b)
// {
// 	ra(a, size_a);
// 	rb(b, size_b);
// }
// void	rra(t_dnode **a, int size_a)
// {
// 	if (size_a <= 1)
// 		return ;
// 	ft_putstr_fd("rra\n", 1);

// 	t_dnode *node_last;
// 	t_dnode *node_second_last;

// 	node_last = *a;
// 	while (node_last->next)
// 	{
// 		node_second_last = node_last;
// 		node_last = node_last->next;
// 	}
// 	node_second_last->next = NULL;
// 	ft_lstadd_front(a, node_last);
// }

// void	rrb(t_dnode **b, int size_b)
// {
// 	if (size_b <= 1)
// 		return ;
// 	ft_putstr_fd("rra\n", 1);

// 	t_dnode *node_last;
// 	t_dnode *node_second_last;

// 	node_last = *b;
// 	while (node_last->next)
// 	{
// 		node_second_last = node_last;
// 		node_last = node_last->next;
// 	}
// 	node_second_last->next = NULL;
// 	ft_lstadd_front(b, node_last);
// }

// void rrr(t_dnode **a, t_dnode **b, int size_a, int size_b)
// {
// 	rra(a, size_a);
// 	rrb(b, size_b);
// }