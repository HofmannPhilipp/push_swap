/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:59:55 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/26 08:16:16 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_dnode *dlist)
{
	int	need_swap = 0;

	
	while (dlist->next)
	{
		if (dlist->value > dlist->next->value)
		{
			need_swap = 1;
			break;
		}
		dlist = dlist->next;
	}
	if (need_swap)
	{
		// ft_printf("Not sorted\n");
		return (0);
	}
	ft_printf("Sorted\n");
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
void ft_print_node(t_dnode *node)
{
	if (node)
	{
		// Werte des Knotens
		printf("\033[0;32m%10d \033[0m%10d %10d", node->value, node->index, node->cost);

		// Werte der Target-Node, falls vorhanden
		if (node->target)
			printf("\tTarget: \033[0;32m%10d\033[0m %10d", node->target->value, node->target->index);
		else
			printf("\tTarget: %10s %10s", "x", "x");
	}
	else
	{
		printf("%10s %10s %10s\tTarget: %10s %10s", "x", "x", "x", "x", "x");
	}
}

// Funktion, um die beiden Stacks nebeneinander zu drucken
void print_stacks(t_dnode *a, t_dnode *b)
{
	t_dnode *curr_a = a;
	t_dnode *curr_b = b;

	// Titelzeile
	printf("\n%10s %10s %10s\t%10s %10s\t\t%10s %10s %10s\t%10s %10s\n", 
			"A-Value", "A-Index", "A-Cost", "Target-Val", "Target-Ind",
			"B-Value", "B-Index", "B-Cost", "Target-Val", "Target-Ind");
	printf("%10s %10s %10s\t%10s %10s\t\t%10s %10s %10s\t%10s %10s\n", 
			"--------", "--------", "--------", "--------", "--------",
			"--------", "--------", "--------", "--------", "--------");

	// Schleife zum Drucken der Knoten
	while (curr_a || curr_b)
	{
		// Print Stack A, falls vorhanden
		if (curr_a)
		{
			ft_print_node(curr_a);
			curr_a = curr_a->next;
		}
		else
		{
			printf("%10s %10s %10s\tTarget: %10s %10s", "x", "x", "x", "x", "x");
		}

		// Tabulator für die Spalte zwischen den Stacks
		printf("\t\t");

		// Print Stack B, falls vorhanden
		if (curr_b)
		{
			ft_print_node(curr_b);
			curr_b = curr_b->next;
		}
		else
		{
			printf("%10s %10s %10s\tTarget: %10s %10s", "x", "x", "x", "x", "x");
		}

		// Zeilenumbruch für die nächste Ebene
		printf("\n");
	}

	// Abschlusszeile
	printf("%10s %10s %10s\t%10s %10s\t\t%10s %10s %10s\t%10s %10s\n",
			"--------", "--------", "--------", "--------", "--------",
			"--------", "--------", "--------", "--------", "--------");
	printf("%10s %10s %10s\t%10s %10s\t\t%10s %10s %10s\t%10s %10s\n",
			"  Stack A", "     ", "     ", "     ", "     ",
			"  Stack B", "     ", "     ", "     ", "     ");
}