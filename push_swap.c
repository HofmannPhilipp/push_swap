/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:53:47 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/15 11:22:22 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
int main(int argc, char *argv[])
{
	if (argc == 1)
		return (ft_putstr_fd("Error \n", 2),1);
	
	int *a;
	int	*b;
	int	i;
	int	size_a;
	int	size_b;
	a = (int *)malloc(sizeof(int) * argc);
	if (!a)
		return (ft_putstr_fd("Error \n", 2),1);
	b = (int *)malloc(sizeof(int) * argc);
	if (!b)
		return (free(a), ft_putstr_fd("Error \n", 2), 1);

	i = 1;
	size_a = argc - 1;
	size_b = 0;
	while (i < argc)
	{
		a[i - 1] = ft_atoi(argv[i]);
		i ++;
	}
	// print_array(a, size_a);
	sa(a, size_a);
	print_array(a, size_a);
	free(a);
	free(b);
}