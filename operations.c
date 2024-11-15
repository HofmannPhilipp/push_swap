/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:27:59 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/15 16:17:43 by phhofman         ###   ########.fr       */
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
