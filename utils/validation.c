/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:24:46 by phhofman          #+#    #+#             */
/*   Updated: 2024/12/09 15:53:01 by phhofman         ###   ########.fr       */
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
	while (ft_iswhitespace(*str) && *str != '\0')
		str ++;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		str ++;
	}
	sum = 0;
	if (!ft_isdigit(*str))
		handle_error();
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			handle_error();
		sum = sum * 10 + (*str - '0');
		str ++;
	}
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

t_dnode	*parse_arguments(int argc, char **argv)
{
	char	**values;
	t_dnode	*a;

	if (argc == 1)
		exit(EXIT_FAILURE);
	if (argc == 2 && argv[1][0] == '\0')
		handle_error();
	if (argc == 2)
	{
		values = ft_split(argv[1], ' ');
		if (!values)
			handle_error();
		a = init_list(values);
		free_values(values);
	}
	else
	{
		values = argv + 1;
		a = init_list(values);
	}
	return (a);
}
