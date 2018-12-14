/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 02:02:08 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/14 13:48:57 by arsciand         ###   ########.fr       */
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

//My conv letter

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
