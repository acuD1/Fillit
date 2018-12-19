/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 02:05:26 by saneveu           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/12/18 13:52:58 by arsciand         ###   ########.fr       */
=======
/*   Updated: 2018/12/18 16:37:46 by saneveu          ###   ########.fr       */
>>>>>>> sam
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fix_neg(t_tetri *tetri)
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
}

void		absolut_coord(t_tetri *tetri)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (tetri->coor[a][b] != 0)
		while (a < 4)
			tetri->coor[a++][b] -= 1;
	a = 0;
	while (tetri->coor[a][b + 1] != 0)
		while (a < 4)
			tetri->coor[a++][b + 1] -= 1;
	fix_neg(tetri);
}

void		fill_coord(char tab[COL][ROW], t_tetri *tetri)
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
	absolut_coord(tetri);
}

int			fill_list(char map[COL][ROW], t_list **list)
{
	t_tetri		 *tetri;

	if (!(tetri = (t_tetri *)ft_memalloc(sizeof(t_tetri))))
		return (0);
	fill_coord(map, tetri);
	ft_list_push_back(list, ft_lstnew(tetri, sizeof(t_tetri)));
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
	list = NULL;
	res = 1;
	n = 0;
	while (res == 1)
	{
		if ((res = ft_reader(fd, map)) == -1)
		{
			ft_putendl("error");
			free_list(&list);
			return (NULL);
		}
		fill_list(map, &list);
<<<<<<< HEAD
		//printmap(map, n++);
	}
	ft_letter_assignation(list);
	//ft_putletter(list);
=======
	}
	ft_letter_assignation(list);
	ft_putletter(list);
>>>>>>> sam
	lst_print(&list);
	close(fd);
	return (list);
}
