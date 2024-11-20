/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 07:56:57 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/20 14:53:50 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	handle_error(void);
int		ft_atoi_plus(const char *str);
void	check_for_duplicates(char **values);
void	free_values(char **values);

#endif