/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:27:59 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/15 18:03:19 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int a[], int size)
{
	if (size <= 1)
		return ;
	int	temp;
	ft_putstr_fd("sa\n", 1);
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}
void	sb(int b[], int size)
{
	if (size <= 1)
		return ;
	int	temp;
	ft_putstr_fd("sb\n", 1);
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
}

void	ss(int a[], int b[], int size_a, int size_b)
{
	sa(a, size_a);
	sb(b, size_b);
}

void	pa(int a[],int b[], int *size_a, int *size_b)
{
	if (*size_b == 0)
		return ;
	ft_putstr_fd("pa\n", 1);
	int i;

	i = *size_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i --;
	}
	*size_a += 1;
	a[0] = b[0];
	
	i = 0;
	while (i < *size_b)
	{
		b[i] = b[i + 1];
		i++;
	}
	*size_b -= 1;
}

void	pb(int a[],int b[], int *size_a, int *size_b)
{
	if (*size_a == 0)
		return ;
	ft_putstr_fd("pb\n", 1);
	int i;

	i = *size_b;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i --;
	}
	*size_b += 1;
	b[0] = a[0];
	
	i = 0;
	while (i < *size_a)
	{
		a[i] = a[i + 1];
		i++;
	}
	*size_a -= 1;
}

void	ra(int	a[], int size_a)
{
	if (size_a <= 1)
		return ;
	ft_putstr_fd("ra\n", 1);
	int	i;
	int temp;

	i = 1;
	temp = a[0];
	while (i < size_a)
	{
		a[i - 1] = a[i];
		i++;
	}
	a[i - 1] = temp;
}
void	rb(int	b[], int size_b)
{
	if (size_b <= 1)
		return ;
	ft_putstr_fd("rb\n", 1);

	int	i;
	int temp;

	i = 1;
	temp = b[0];
	while (i < size_b)
	{
		b[i - 1] = b[i];
		i++;
	}
	b[i - 1] = temp;
}
void	rra(int a[], int size_a)
{
	if (size_a <= 1)
		return ;
	ft_putstr_fd("rra\n", 1);

	int temp;

	temp = a[size_a - 1];
	size_a --;
	while (size_a >= 0)
	{
		a[size_a] = a[size_a - 1];
	 size_a --;
	}
	a[0] = temp;
}
void	rrb(int b[], int size_b)
{
	if (size_b <= 1)
		return ;
	ft_putstr_fd("rrb\n", 1);

	int temp;

	temp = b[size_b - 1];
	size_b --;
	while (size_b >= 0)
	{
		b[size_b] = b[size_b - 1];
	 size_b --;
	}
	b[0] = temp;
}

void rrr(int a[], int b[], int size_a, int size_b)
{
	rra(a, size_a);
	rrb(b, size_b);
}