/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:53:47 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/18 16:05:24 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
int main(int argc, char *argv[])
{
	if (argc == 1)
		return (ft_putstr_fd("Error \n", 2),1);
	
	t_list *a;
	t_list *b;
	int	i;
	int	size_a;
	int	size_b;
	int	*val;
	size_a = argc - 1;
	size_b = 0;
	
	a = NULL;
	b = NULL;
	i = 1;
	while(i < argc)
	{
		val =(int *)malloc(sizeof(int));
		if (!val)
			return (ft_putstr_fd("Error \n", 2),1);
		*val = ft_atoi(argv[i]);
		ft_lstadd_back(&a, ft_lstnew(val));
		i ++;
	}
	print_list(a, b, size_a, size_b);
	rra(&a, size_a);
	print_list(a, b, size_a, size_b);
	free(a);
	free(b);
}
