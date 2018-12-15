/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 02:05:26 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/15 06:54:15 by saneveu          ###   ########.fr       */
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

int			fill_list(char map[COL][ROW], t_list **first)
{
	t_tetri 		*tetri;

	if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);		// Ou fonction error
	tetri = fill_coord(map, tetri);																				//A DELETE
	ft_list_push_back(first, tetri);
	printf("pushback succed\n\n"); //A DELEt
	return (1);
}

list		ft_parser(char *file)//map de [4][6] pour \n et oel
{
	char	map[COL][ROW];
	int		fd;
	int		res;
	int		n;
	t_list	*list;
	t_list	**begin_list;

	if (!(fd = (open(file, O_RDONLY))))
		return (NULL);
	if(!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	res = 1;
	n = 0;
	while (res == 1)
	{
		if ((res = ft_reader(fd, map)) == -1)
		{
			free(list);
			return (NULL);
		}
		printmap(map, n++);
		begin_list = &list;
		fill_list(map, begin_list);
	}
	printf("size de la list : %zu\n", ft_lstsize(list));
	printf("FIN du PGR et retour reader : %d\n", res);
	close(fd);
	//free(map);
	return (list);
}
