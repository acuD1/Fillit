/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:32:35 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/09 19:02:15 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		nb_link(char map[COL][ROW])
{
	int		x;
	int		y;
	int		link;

	link = 0;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 5)
		{
			if (map[x][y] == '#')
			{
				map[x + 1][y] == '#' ? link += 2 : link;
				map[x][y + 1] == '#' ? link += 2 : link;
			}
			y++;
		}
		x++;
	}
	return (link);
}

int     ft_verif(char *c, t_verif *verif)
{
	if (*c == '#')
		verif->hash += 1;
	else if (*c == '.')
		verif->p += 1;
	else if (*c == '\n')
		verif->eol += 1;
	else
		return (-1);
	return (1);
}

/*
int		check_tetri(char **tetri)
{
	int		res;
	int		x;
	int		y;
	t_verif verif;

	verif.hash = 0;
	verif.p = 0;
	verif.eol = 0;
	x = 0;
	while (tetri[x])
	{
		y = 0;
		while (tetri[x][y])
		{
			if (ft_verif(tetri[x][y], &verif))
				y++;
			else
				return (-1);
		}
	}
	res = nb_link(tetri);
	if ((verif.hash != 4 || verif.p != 12 || verif.eol != 4) 
			&& (res == 6 || res == 8))
		return (1);
	return (0);
	//check
	//si valid -> mettre les coor rela dans struct
}
*/

/*
int		fill_list(char tab[COL][ROW])
{
	t_list  *lst;
	t_tetri *tetri;
	int		x;
	int		i;

	if (!(tetri = ft_memalloc(sizeof(t_tetri))))
		return (0);
	if (check_tetri(tab))
		tetri->matrix = ft_strdup(tab);
	lst->content = &tetri;
	return (0);
}
*/

int     ft_reader(int fd, char map[COL][ROW], int *n_read)//map de [4][6] pour \n et oel
{
	char    buff[BUFF_LEN];
	t_verif verif;
	int     x;
	int     y;

	ft_init(map, &verif);
	*n_read = 1;
	x = 0;
	while (x < 4) 
	{
		y = 0;
		while (y < 5)
		{
			if (((*n_read = read(fd, buff, 1)) > 0) && (ft_verif(buff, &verif) == 1))
					map[x][y] = *buff;
			y++;
		}
		map[x][y] = '\0';
		x++;
	}
	if (verif.hash != 4 || verif.p != 12 || verif.eol != 4)
		return (-1);
	else if (nb_link(map) == 6 || nb_link(map) == 8)
		return (1);
	return (0);
}

int     ft_parser(char *file)//map de [4][6] pour \n et oel
{
	char	map[COL][ROW];
	int		n_read;
	int		fd;
	int		i;
	int		res;

	if (!(fd = (open(file, O_RDONLY))))
	{
		ft_putendl("error");
		return (-1);
	}
	res = 1;
	if ((res = ft_reader(fd, map, &n_read)) == -1)
	{
		ft_putendl("error");
		return (-1);
	}
	i = 0;
	while (i < 4)
	{
		ft_putstr(map[i]);
		i++;
	}
	//fill_list(map[COL][ROW]);
	close(fd);
	return (0);
}
