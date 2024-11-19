/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:53:47 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/19 13:24:47 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
int main(int argc, char *argv[])
{
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (ft_putstr_fd("Error \n", 2),1);
	char **values;
	if (argc == 2)
	{
		
		values = ft_split(argv[1], ' ');
		if (!values)
			return (ft_putstr_fd("Error \n", 2),1);
		

	}
	else
	{
		t_dnode *a;
		t_dnode *b;
		int	i;
		int	val;

		a = NULL;
		b = NULL;
		i = 1;
		while(i < argc)
		{
			val = ft_atoi(argv[i]);
			if (!a)
				a = create_dnode(val);
			else 
				add_back_dlst(&a, create_dnode(val));
			i ++;
		}
		print_dlst(a, b, argc - 1, 0);
	}

	// free(a);
	// free(b);
}
