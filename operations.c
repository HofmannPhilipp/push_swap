/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:27:59 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/18 16:26:46 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *a, int size)
{
	if (size <= 1 || !a || !a->next)
		return ;
	int	*temp;
	ft_putstr_fd("sa\n", 1);
	temp = (int *)a->content;
	a->content = a->next->content;
	a->next->content = temp;
}
void	sb(t_list *b, int size)
{
	if (size <= 1)
		return ;
	int	*temp;
	ft_putstr_fd("sb\n", 1);
	temp = (int *)b->content;
	b->content = b->next->content;
	b->next->content = temp;
}

void	ss(t_list *a, t_list *b, int size_a, int size_b)
{
	sa(a, size_a);
	sb(b, size_b);
}

void	pa(t_list **a, t_list **b, int *size_a, int *size_b)
{
	if (*size_b == 0)
		return ;
	ft_putstr_fd("pa\n", 1);
	t_list *node;

	node = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, node);
	*size_a += 1;
	*size_b -= 1;
}

void	pb(t_list **a, t_list **b, int *size_a, int *size_b)
{
	if (*size_a == 0)
		return ;
	ft_putstr_fd("pb\n", 1);
	t_list *node;

	node = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, node);
	*size_b += 1;
	*size_a -= 1;
}

void	ra(t_list **a, int size_a)
{
	if (size_a <= 1)
		return ;
	ft_putstr_fd("ra\n", 1);
	
	t_list *node_first;

	node_first = *a;
	ft_lstadd_back(a, node_first);
	*a = (*a)->next;
	node_first->next = NULL;
}
void	rb(t_list **b, int size_b)
{
	if (size_b <= 1)
		return ;
	ft_putstr_fd("rb\n", 1);
	t_list *node_first;

	node_first = *b;
	ft_lstadd_back(b, node_first);
	*b = (*b)->next;
	node_first->next = NULL;
}

void	rr(t_list **a, t_list **b, int size_a, int size_b)
{
	ra(a, size_a);
	rb(b, size_b);
}
void	rra(t_list **a, int size_a)
{
	if (size_a <= 1)
		return ;
	ft_putstr_fd("rra\n", 1);

	t_list *node_last;
	t_list *node_second_last;

	node_last = *a;
	while (node_last->next)
	{
		node_second_last = node_last;
		node_last = node_last->next;
	}
	node_second_last->next = NULL;
	ft_lstadd_front(a, node_last);
}

void	rrb(t_list **b, int size_b)
{
	if (size_b <= 1)
		return ;
	ft_putstr_fd("rra\n", 1);

	t_list *node_last;
	t_list *node_second_last;

	node_last = *b;
	while (node_last->next)
	{
		node_second_last = node_last;
		node_last = node_last->next;
	}
	node_second_last->next = NULL;
	ft_lstadd_front(b, node_last);
}

void rrr(t_list **a, t_list **b, int size_a, int size_b)
{
	rra(a, size_a);
	rrb(b, size_b);
}