/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 02:05:26 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/14 15:17:28 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*fill_coord(char tab[COL][ROW])
{
	t_tetri		*tetri;
	int			x;
	int			y;
	int			a;
	int			b;

	x = 0;
	y = 0;
	if(!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
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
	return (tetri);
}

int			fill_list(char map[COL][ROW], list first)
{
	t_tetri 		*tetri;

	if (!(tetri = fill_coord(map)))
	{
		free(tetri);
		return (0);
	}
	printcoor(tetri);	//A DELETE
	if (first->next == NULL)
		first->next = ft_lstnew(&tetri, sizeof(t_tetri));
	else
	{
		ft_list_push_back(&first, tetri);
		printf("pushback succed\n\n"); //A DELETE
	}
	return (1);
}

list		ft_parser(char *file)//map de [4][6] pour \n et oel
{
	char	map[COL][ROW];
	int		fd;
	int		res;
	int		n;
	list	list;

	if(!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(fd = (open(file, O_RDONLY))))
		return (NULL);
	res = 1;
	n = 0;
	while (res == 1)
	{
		if ((res = ft_reader(fd, map)) == -1)
		{
			ft_putendl("error");
			return (NULL);
		}
		printmap(map, n++);
		if (!(fill_list(map, list)))
			return (NULL);
	}
	printf("size de la list : %zu\n", ft_lstsize(list));
	printlist(list);
	printf("FIN du PGR et retour reader : %d\n", res);
	close(fd);
	return (0);
}
