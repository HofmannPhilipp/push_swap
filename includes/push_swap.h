/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:53:51 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/27 14:28:48 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "list.h"
# include "utils.h"
# include <stdio.h>
# include <stdlib.h>

// instructions
void	sa(t_dnode *a);
void	sb(t_dnode *a);
void	ss(t_dnode *a, t_dnode *b);
void	pa(t_dnode **a, t_dnode **b);
void	pb(t_dnode **a,t_dnode **b);
void	ra(t_dnode **a, int print);
void	rb(t_dnode **b, int print);
void	rr(t_dnode **a, t_dnode **b, int print);
void	rra(t_dnode **a, int print);
void	rrb(t_dnode **b, int print);
void	rrr(t_dnode **a, t_dnode **b, int print);


// sort
void	sort_three(t_dnode **list);
void	calc_cheapest(t_dnode *a, t_dnode *b);
void	turk_sort(t_dnode **a, t_dnode **b);

// rotate_helpers
void	rotate_if_both_above_mid(t_dnode **a, t_dnode **b, t_dnode *cheapest);
void	rotate_if_both_below_mid(t_dnode **a, t_dnode **b, t_dnode *cheapest);
void	rotate_seperate(t_dnode **a, t_dnode **b, t_dnode *cheapest, int size_a, int size_b);

#endif