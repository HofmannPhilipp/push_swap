/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:53:47 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/20 11:13:23 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
 
int main(int argc, char *argv[])
{
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (ft_putstr_fd("Error \n", 2),1);
	char **values;
	t_dnode *a;
	t_dnode *b;
	if (argc == 2)
	{
		
		values = ft_split(argv[1], ' ');
		if (!values)
			return (ft_putstr_fd("Error \n", 2),1);
	}
	else
		values = argv + 1;
	a = init_dlst(values);
	b = NULL;
	print_dlst(a, b);
	ra(&a);
	print_dlst(a, b);
	rra(&a);
	print_dlst(a, b);
	// free(a);
	// free(b);
}
