/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:53:51 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/15 14:53:02 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

void	print_array(int a[], int b[], int size_a, int size_b);
void	sa(int a[], int size);
void	sb(int a[], int size);
void	ss(int a[], int b[], int size_a, int size_b);
void	pa(int a[],int b[], int *size_a, int *size_b);
void	pb(int a[],int b[], int *size_a, int *size_b);


#endif