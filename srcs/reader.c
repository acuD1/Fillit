/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:32:35 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/12 02:58:34 by saneveu          ###   ########.fr       */
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
				if (map[x + 1][y] == '#' || map[x][y +1] == '#')
					link += 2;
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

int		next_tetri(int fd, char *buff)
{
	int ret;

	ret = 0;
	if ((ret = read(fd, buff, 1)) == 0)
		return (0);
	if (*buff == '\n')
		return (1);
	return (0);
}

int     ft_reader(int fd, char map[COL][ROW])//map de [4][6] pour \n et oel
{
	char    buff[BUFF_LEN];
	t_verif verif;
	int     x;
	int     y;
	int		res;

	ft_init(map, &verif);
	res = 1;
	x = 0;
	while (x < 4) 
	{
		y = 0;
		while (y < 5)
		{
			if (((res = read(fd, buff, 1)) > 0)
			&& (ft_verif(buff, &verif) == 1))
					map[x][y] = *buff;
			y++;
		}
		map[x][y] = '\0';
		x++;
	}
	res = nb_link(map);
	//printf("%d\n", res);
	if ((verif.hash != 4 || verif.p != 12 || verif.eol != 4) 
	|| !(res == 6 || res == 8)) 
			return (-1);
	//faire un read de 1 si c'est un \n return 1
	return (next_tetri(fd, buff));
}

