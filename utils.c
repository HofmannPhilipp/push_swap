/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:59:55 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/18 13:11:15 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(int a[], int b[], int size_a, int size_b)
{
	int	i;
	int	max;

	i = 0;
	if (size_a <= size_b)
		max = size_b;
	else 
		max = size_a;
	while (i < max)
	{
		if (i < size_a)
			ft_putnbr_fd(a[i], 1);
		else 
			ft_putchar_fd('x', 1);
		ft_putchar_fd('\t',1);
		if (i < size_b)
			ft_putnbr_fd(b[i], 1);
		else 
			ft_putchar_fd('x', 1);
		ft_putchar_fd('\n', 1);
		i ++;
	}
	ft_putstr_fd("_	_\n",1);
	ft_putstr_fd("a	b\n",1);
}
void	print_list(t_list *a, t_list *b, int size_a, int size_b)
{
	int	i;
	int	max;

	i = 0;
	if (size_a <= size_b)
		max = size_b;
	else 
		max = size_a;
	while (i < max)
	{
		if (i < size_a)
		{
			ft_putnbr_fd(*(int *)a->content, 1);
			a = a->next;
		}
		else 
			ft_putchar_fd('x', 1);
		ft_putchar_fd('\t',1);
		if (i < size_b)
		{
			ft_putnbr_fd(*(int *)b->content, 1);
			b = b->next;
		}
		else 
			ft_putchar_fd('x', 1);
		ft_putchar_fd('\n', 1);
		i ++;
	}
	ft_putstr_fd("_	_\n",1);
	ft_putstr_fd("a	b\n",1);
}

int	is_sorted(int a[], int size_a)
{
	int	i;
	int	need_swap = 0;

	i = 0;
	while (i + 1 < size_a)
	{
		if (a[i] > a[i + 1])
		{
			need_swap = 1;
			break;
		}
		i ++;
	}
	if (need_swap)
	{
		ft_putstr_fd("Not sorted\n",1);
		return (0);
	}
	ft_putstr_fd("Sorted\n", 1);
	return (1);

}
