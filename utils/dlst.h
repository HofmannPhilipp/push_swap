/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:36:37 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/19 13:21:05 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLST_H
# define DLST_H

# include <stdio.h>
# include <stdlib.h>

// typedef struct s_stack
// {
// 	t_dnode *top;
// 	int		size;
// }	t_stack;

typedef struct s_dnode
{
	int		value;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}	t_dnode;

// t_dnode	*init_dlst(char **values, int values_size);
t_dnode	*create_dnode(int value);
void	push_dlst(t_dnode **head, t_dnode *node);
t_dnode *pop_dlst(t_dnode **head);
t_dnode	*get_dlst_last(t_dnode *head);
void	add_back_dlst(t_dnode **head, t_dnode *new_node);
int		get_dlst_size(t_dnode *head);
void	print_dlst(t_dnode *a, t_dnode *b, int size_a, int size_b);

# endif