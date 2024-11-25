/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:53:51 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/25 16:57:45 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "dlst.h"
# include "utils.h"
# include "../utils/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

// instructions
void	sa(t_dnode *a);
void	sb(t_dnode *a);
void	ss(t_dnode *a, t_dnode *b);
void	pa(t_dnode **a, t_dnode **b);
void	pb(t_dnode **a,t_dnode **b);
void	ra(t_dnode **a);
void	rb(t_dnode **b);
void	rr(t_dnode **a, t_dnode **b);
void	rra(t_dnode **a);
void	rrb(t_dnode **b);
void	rrr(t_dnode **a, t_dnode **b);

t_dnode	*get_max(t_dnode *dlist);
void	sort_three(t_dnode **dlist);
void	set_target_node_min(t_dnode **a, t_dnode **b);
t_dnode	*get_cheapest(t_dnode *list);
void	calc_cheapest(t_dnode *a, t_dnode *b);
void	turk_sort(t_dnode **a, t_dnode **b);



#endif