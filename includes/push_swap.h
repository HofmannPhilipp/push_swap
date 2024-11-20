/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:53:51 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/20 11:20:56 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "dlst.h"
# include "../utils/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

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

#endif