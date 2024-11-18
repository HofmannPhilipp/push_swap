/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:53:51 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/18 16:27:14 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

void	print_array(int a[], int b[], int size_a, int size_b);
void	sa(t_list *a, int size);
void	sb(t_list *a, int size);
void	ss(t_list *a, t_list *b, int size_a, int size_b);
void	pa(t_list **a, t_list **b, int *size_a, int *size_b);
void	pb(t_list **a,t_list **b, int *size_a, int *size_b);
void	ra(t_list **a, int size_a);
void	rb(t_list **b, int size_a);
void	rr(t_list **a, t_list **b, int size_a, int size_b);
void	rra(t_list **a, int size_a);
void	rrb(t_list **b, int size_a);
void	rrr(t_list **a, t_list **b, int size_a, int size_b);
// int		is_sorted(t_list *a, int size_a);
void	print_list(t_list *a, t_list *b, int size_a, int size_b);

#endif