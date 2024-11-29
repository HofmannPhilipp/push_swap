/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:59:55 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/29 10:41:58 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handle_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_dnode *dlist)
{
	int	need_swap;

	need_swap = 0;
	while (dlist->next)
	{
		if (dlist->value > dlist->next->value)
		{
			need_swap = 1;
			break ;
		}
		dlist = dlist->next;
	}
	if (need_swap)
		return (0);
	return (1);
}

void	free_values(char **values)
{
	int	i;

	if (!values)
		return ;
	i = 0;
	while (values[i] != NULL)
	{
		free(values[i]);
		i++;
	}
	free(values);
}

void	calc_cheapest(t_dnode *a, t_dnode *b)
{
	int	size_a;
	int	size_b;

	size_a = get_list_size(a);
	size_b = get_list_size(b);
	while (a)
	{
		if (a->index <= size_a / 2)
			a->cost = a->index;
		else
			a->cost = size_a - a->index;
		if (a->target->index <= size_b / 2)
			a->cost += a->target->index;
		else
			a->cost += size_b - a->target->index;
		a = a->next;
	}
}
