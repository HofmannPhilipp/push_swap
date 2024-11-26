/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:59:55 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/26 14:30:39 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handle_error(void)
{
	ft_putstr_fd("Error\n",2);
	exit(1);
}

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

	// Header
	printf("\n%10s %10s %10s   %10s %10s     %10s %10s %10s   %10s %10s\n",
			"A-Value", "A-Index", "A-Cost", "T-Value", "T-Index",
			"B-Value", "B-Index", "B-Cost", "T-Value", "T-Index");
	printf("%10s %10s %10s   %10s %10s     %10s %10s %10s   %10s %10s\n",
			"--------", "--------", "--------", "--------", "--------",
			"--------", "--------", "--------", "--------", "--------");

	// Rows
	while (curr_a || curr_b)
	{
		// Print Stack A values
		if (curr_a)
		{
			printf("\033[0;32m%10d\033[0m %10d %10d   ", curr_a->value, curr_a->index, curr_a->cost);
			if (curr_a->target)
				printf("\033[0;32m%10d\033[0m %10d   ", curr_a->target->value, curr_a->target->index);
			else
				printf("%10s %10s   ", "x", "x");
			curr_a = curr_a->next;
		}
		else
		{
			printf("%10s %10s %10s   %10s %10s   ", "x", "x", "x", "x", "x");
		}

		// Print Stack B values
		if (curr_b)
		{
			printf("\033[0;32m%10d\033[0m %10d %10d   ", curr_b->value, curr_b->index, curr_b->cost);
			if (curr_b->target)
				printf("\033[0;32m%10d\033[0m %10d", curr_b->target->value, curr_b->target->index);
			else
				printf("%10s %10s", "x", "x");
			curr_b = curr_b->next;
		}
		else
		{
			printf("%10s %10s %10s   %10s %10s", "x", "x", "x", "x", "x");
		}

		printf("\n"); // Move to the next row
	}

	// Footer
	printf("%10s %10s %10s   %10s %10s     %10s %10s %10s   %10s %10s\n",
			"--------", "--------", "--------", "--------", "--------",
			"--------", "--------", "--------", "--------", "--------");
	printf("%10s %10s %10s   %10s %10s     %10s %10s %10s   %10s %10s\n",
			"   Stack A", "", "", "", "",
			"   Stack B", "", "", "", "");
}
