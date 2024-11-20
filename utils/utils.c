/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:59:55 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/20 15:49:49 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	is_sorted(int a[], int size_a)
// {
// 	int	i;
// 	int	need_swap = 0;

// 	i = 0;
// 	while (i + 1 < size_a)
// 	{
// 		if (a[i] > a[i + 1])
// 		{
// 			need_swap = 1;
// 			break;
// 		}
// 		i ++;
// 	}
// 	if (need_swap)
// 	{
// 		ft_putstr_fd("Not sorted\n",1);
// 		return (0);
// 	}
// 	ft_putstr_fd("Sorted\n", 1);
// 	return (1);

// }

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

void	handle_error(void)
{
	ft_putstr_fd("Error\n",2);
	exit(1);
}

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
	if (!ft_isdigit(*str) && *str != '\0')
		handle_error();
	if (sign * sum > INT_MAX || sign * sum < INT_MIN)
		handle_error();
	return (sign * sum);
}

void	check_for_duplicates(t_dnode **head)
{
	t_dnode *left;
	t_dnode *right;

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
