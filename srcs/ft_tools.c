/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 02:02:08 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/14 15:17:25 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_init(char map[COL][ROW], t_verif *verif)
{
	int c;

	c = COL;
	verif->hash = 0;
	verif->p = 0;
	verif->eol = 0;
	while (c--)
		ft_bzero(map[c], ROW);
}

void			ft_letter(list first)
{
	t_list		*list;
	t_tetri		*tetri;
	char		c;

	c = 'A';
	list = first;
	while (list)
	{
		tetri = list->content;
		tetri->letter = c;
		c += 1;
		list = list->next;
	}
}

void	ft_letter_assignation(list first, t_tetri *tetri)
{
	int		cnt;
	list	tmp;

	tmp = first;
	cnt = 0;
	while (tmp)
	{
		tetri->letter = (char)('A' + cnt);
		cnt++;
		tmp = tmp->next;
	}
}

//BETA FUNCTIONS

void	convert(char map[COL][ROW], char c)
{
	int x;
	int y;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 5)
		{
			if (map[x][y] == '#')
				map[x][y] = (char)c;
		}
	}
}

void	printlist(list first)
{
	t_list	*link;

	link = first;
	while (link != NULL)
	{
		printf("%d\n", (char)link->content + '0');
		link = link->next;
	}
}

void	printcoor(t_tetri *tetri)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetri->coor[i][j])
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
		printf("%s", map[i++]);
}
