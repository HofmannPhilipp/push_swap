/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:27:59 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/15 11:24:18 by phhofman         ###   ########.fr       */
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
