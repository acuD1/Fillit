/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:49:14 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/16 17:09:18 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	printlist(t_list *first)
{
	t_list		*link;
	t_tetri		*tmp;
	char		letter;

	if (!first)
		ft_putstr("error. empty list");
	tmp = first->content;
	letter = tmp->letter;
	link = first;
	while (link)
	{
		printf("[%d]->", letter);
		link = link->next;
	}
}

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
