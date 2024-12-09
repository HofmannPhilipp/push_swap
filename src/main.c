/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:53:47 by phhofman          #+#    #+#             */
/*   Updated: 2024/12/09 10:47:55 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_dnode	*a;
	t_dnode	*b;

	a = parse_arguments(argc, argv);
	b = NULL;
	check_for_duplicates(&a);
	turk_sort(&a, &b);
	free_list(&a);
	free_list(&b);
	exit(EXIT_SUCCESS);
}
