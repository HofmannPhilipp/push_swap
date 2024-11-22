/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:50:18 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/22 10:24:48 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max(t_dnode *dlist)
{
	int	max;
	int	index;

	max = dlist->value;
	index = dlist->index;
	while (dlist)
	{
		if (max < dlist->value)
		{
			max = dlist->value;
			index = dlist->index;
		}
		dlist = dlist->next;
	}
	return (max);
}

void	radix_sort(t_dnode **a, t_dnode **b)
{
	int	max;
	int	i;

	max = get_max(&a);
	i = 1;
	while (max / i > 0)
	{
		
		i *= 10;
	}

}