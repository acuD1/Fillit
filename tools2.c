/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:49:14 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/23 07:57:13 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		ft_sqrt_supp(int nb)
{
	int i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i * i < nb)
		i++;
	return (i);
}

void	ft_b_point(char **map, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			map[i][j++] = '.';
		map[i][j] = '\0';
		i++;
	}
}

void	ft_display_final_map(char **final_map)
{
	int i;

	i = 0;
	while (final_map[i])
		ft_putendl(final_map[i++]);
	ft_free_map(final_map);
}

void	ft_free_map(char **map)
{
	int		i;

	i = -1;
	if (map != NULL && *map != NULL)
	{
		while (map[++i] != NULL)
		{
			free(map[i]);
			map[i] = NULL;
		}
		free(map);
		map = NULL;
	}
}
