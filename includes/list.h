/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:36:37 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/26 17:14:48 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_dnode
{
	int				value;
	int				index;
	// int				size;
	// int				mid;
	int				cost;
	struct s_dnode	*target;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}	t_dnode;

typedef struct s_stack
{
	t_dnode *a;
	t_dnode *b;
	int		size_a;
	int		size_b;
}	t_stack;


// init_list
t_dnode	*init_list(char **values);
void	set_list_index(t_dnode *list);
void	set_nearest_smaller_target(t_dnode **a, t_dnode **b);
void	set_nearest_bigger_target(t_dnode **a, t_dnode **b);

// list_operations
t_dnode	*create_node(int value, int index);
void	push(t_dnode **list, t_dnode *node);
t_dnode *pop(t_dnode **list);
void	add_to_list_back(t_dnode **list, t_dnode *new_node);

// list_getters
t_dnode	*get_last_node(t_dnode *list);
t_dnode	*get_max_node(t_dnode *list);
t_dnode	*get_min_node(t_dnode *list);
int		get_list_size(t_dnode *list);
t_dnode	*get_cheapest_node(t_dnode *list);

// print_list
void	print_list(t_dnode *a, t_dnode *b);
void	print_node(t_dnode *node);

// free_list
void	free_list(t_dnode **list);

# endif