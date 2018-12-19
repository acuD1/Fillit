/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:49:14 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/18 03:00:21 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	printcoor(t_tetri *tetri)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		printf("#|%d|", i);
		printf("y = %d ", tetri->coor[i][j]);
		printf("x = %d ", tetri->coor[i][j + 1]);
		printf("\n");
		i++;
	}
	printf("-----------------\n");
}

void	printmap(char map[COL][ROW], int n)
{
	int i;

	i = 0;
	printf("MAP %d\n", n);
	while (i < 4)
		ft_putstr(map[i++]);
}

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
}