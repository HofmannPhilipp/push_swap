/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:53:47 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/29 08:42:43 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	char	**values;
	t_dnode	*a;
	t_dnode	*b;

	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
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
	check_for_duplicates(&a);
	b = NULL;
	turk_sort(&a, &b);
	free_list(&a);
	free_list(&b);
	exit(EXIT_SUCCESS);
}
