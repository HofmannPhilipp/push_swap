/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:27:59 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/20 11:22:52 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_dnode *a)
{
	if (!a || !a->next)
		return ;
	int	temp;
	ft_printf("sa\n");
	temp = a->value;
	a->value = a->next->value;
	a->next->value = temp;
}
void	sb(t_dnode *b)
{
	if (!b || !b->next)
		return ;
	int	temp;
	ft_printf("sa\n");
	temp = b->value;
	b->value = b->next->value;
	b->next->value = temp;
}

void	ss(t_dnode *a, t_dnode *b)
{
	sa(a);
	sb(b);
}

void	pa(t_dnode **a, t_dnode **b)
{
	if (!*b || !(*b)->next)
		return ;
	ft_printf("pa\n");
	t_dnode *node;

	node = pop_dlst(b);
	push_dlst(a, node);
}

void	pb(t_dnode **a, t_dnode **b)
{
	if (!*a || !(*a)->next)
		return ;
	ft_printf("pb\n");
	t_dnode *node;

	node = pop_dlst(a);
	push_dlst(b, node);
}

void	ra(t_dnode **a)
{
	if (!*a || !(*a)->next)
		return ;
	ft_printf("ra\n");
	
	t_dnode *first;
	t_dnode *last;

	first = *a;
	last = get_dlst_last(*a);
	last->next = first;
	*a = (*a)->next;
	first->prev = last;
	first->next = NULL;
}
void	rb(t_dnode **b)
{
	if (!*b || !(*b)->next)
		return ;
	ft_printf("rb\n");
	
	t_dnode *first;
	t_dnode *last;

	first = *b;
	last = get_dlst_last(*b);
	last->next = first;
	*b = (*b)->next;
	first->prev = last;
	first->next = NULL;
}

void	rr(t_dnode **a, t_dnode **b)
{
	ra(a);
	rb(b);
}
void	rra(t_dnode **a)
{
	if (!*a || !(*a)->next)
		return ;
	ft_printf("rra\n");
	
	t_dnode *last;

	last = get_dlst_last(*a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *a;
	*a = last;
}

void	rrb(t_dnode **b)
{
	if (!*b || !(*b)->next)
		return ;
	ft_printf("rrb\n");
	
	t_dnode *last;

	last = get_dlst_last(*b);
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *b;
	*b = last;
}

void rrr(t_dnode **a, t_dnode **b)
{
	rra(a);
	rrb(b);
}
