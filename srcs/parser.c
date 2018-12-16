/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 02:05:26 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/16 17:27:06 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*fix_neg(t_tetri *tetri)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (a < 4)
	{
		if (tetri->coor[a][b] < 0)
		{
			a = 0;
			while (a < 4)
				tetri->coor[a++][b] += 1;
		}
		a++;
	}
	return (tetri);
}

t_tetri		*absolut_coord(t_tetri *tetri)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (tetri->coor[a][b] && tetri->coor[a][b] != 0)
		while (a < 4)
			tetri->coor[a++][b] -= 1;
	a = 0;
	while (tetri->coor[a][b + 1] && tetri->coor[a][b + 1] != 0)
		while (a < 4)
			tetri->coor[a++][b + 1] -= 1;
	return (fix_neg(tetri));
}

t_tetri		*fill_coord(char tab[COL][ROW], t_tetri *tetri)
{
	int			x;
	int			y;
	int			a;
	int			b;

	x = 0;
	y = 0;
	a = 0;
	while (a < 4)
	{
		b = 0;
		while (b < 5)
		{
			if (tab[a][b] == '#')
			{
				tetri->coor[x][y] = a;
				tetri->coor[x][y + 1] = b;
				x++;
			}
			b++;
		}
		a++;
	}
	tetri = absolut_coord(tetri);
	printcoor(tetri);
	return (tetri);
}

int			fill_list(char map[COL][ROW], t_list **list)
{
	t_tetri		*tetri;

	if (!(tetri = ft_memalloc(sizeof(t_tetri))))
		return (0);
	tetri = fill_coord(map, tetri);
	ft_list_push_back(list, tetri);
	free(tetri);
	return (1);
}

t_list		*ft_parser(char *file)
{
	char	map[COL][ROW];
	int		fd;
	int		res;
	int		n;
	t_list	*list;

	if (!(fd = (open(file, O_RDONLY))))
		return (NULL);
	if (!(list = ft_memalloc(sizeof(t_list))))
		return (NULL);
	res = 1;
	n = 0;
	while (res == 1)
	{
		if ((res = ft_reader(fd, map)) == -1)
		{
			ft_putendl("error");
			free(list);
			return (NULL);
		}
		printmap(map, n++);
		fill_list(map, &list);
	}
	close(fd);
	return (list);
}
