/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:53:47 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/25 10:29:20 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
 
int main(int argc, char *argv[])
{
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		handle_error();
	char **values;
	t_dnode *a;
	t_dnode *b;
	if (argc == 2)
	{
		
		values = ft_split(argv[1], ' ');
		if (!values)
			handle_error();
		a = init_dlist(values);
		free_values(values); 
	}
	else
	{
		values = argv + 1;
		a = init_dlist(values);
	}
	check_for_duplicates(&a);
	b = NULL;
	print_dlist(a, b);
	pb(&a, &b);
	pb(&a, &b);
	print_dlist(a, b);
	set_target_node_min(&a, &b);
	free_dlist(&a);
	free_dlist(&b);
	exit(EXIT_SUCCESS);
}
