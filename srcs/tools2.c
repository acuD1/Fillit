/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:49:14 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/20 02:50:23 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt_supp(int nb)
{
	int i;

	i = 0;
	if (nb <= 0)
		return (0);
	while(i * i < nb)
		i++;
	return (i);
}

void	b_point(char **map, int size)
{
	int i;
	int j;

	i = 0;
	while(i < size)
	{
		j = 0;
		while(j < size)
			map[i][j++] = '.';
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
}

void	ft_display_final_map(char **final_map)
{
	while(*final_map)
		ft_putendl(*final_map++);
}	
