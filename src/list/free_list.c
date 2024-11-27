/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:11:11 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/27 14:24:54 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_list(t_dnode **list)
{
	if (!list || !*list)
		return ;
		
	t_dnode *temp;
	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
	*list = NULL;
}
