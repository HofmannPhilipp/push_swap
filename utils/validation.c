/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:24:46 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/29 11:47:49 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_iswhitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi_plus(const char *str)
{
	int		sign;
	long	sum;

	sign = 1;
	while (ft_iswhitespace(*str) && *str)
		str ++;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		str ++;
	}
	sum = 0;
	while (ft_isdigit(*str))
	{
		sum = sum * 10 + (*str - '0');
		str ++;
	}
	if (*str != '\0')
		handle_error();
	if (sign * sum > INT_MAX || sign * sum < INT_MIN)
		handle_error();
	return (sign * sum);
}

void	check_for_duplicates(t_dnode **head)
{
	t_dnode	*left;
	t_dnode	*right;

	left = *head;
	while (left)
	{
		right = left->next;
		while (right)
		{
			if (left->value == right->value)
				handle_error();
			right = right->next;
		}
		left = left->next;
	}
}
