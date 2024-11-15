/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:59:55 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/15 14:20:38 by phhofman         ###   ########.fr       */
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
