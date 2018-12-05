/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:32:35 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/05 14:42:43 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		nb_link(char map[4][6])
{
	int		x;
	int		y;
	int		link;

	link = 0;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 6)
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
	{
		verif->hash += 1;
		return (1);
	}
	else if (*c == '.')
	{
		verif->p += 1;
		return (1);
	}
	else if (*c == '\n')
	{
		verif->eol += 1;
		return (1);
	}
	else
		return (0);
}

int     ft_reader(int fd, int *n_read)//map de [4][6] pour \n et oel
{
	int     res;
	char	*tetri[4];
	char    *buff;
	t_verif verif;
	int     i;

	*n_read = 1;
	verif.hash = 0;
	verif.p = 0;
	verif.eol = 0;
	//open
	/*while (x < 4) 
	{
		y = 0;
		while (y < 6)
		{
			if ((*n_read = read(fd, buff, 1)) > 0)
				if (ft_verif(buff, &verif) == 1)
					map[x][y] = *buff;
			y++;
		}
		map[x][y] = '\0';
		x++;
	}*/
	i = 0;
	while (get_next_line(fd, &buff) && i < 4)
		tetri[i++] = ft_strdup(buff);
	/*if (verif.hash != 4 || verif.p != 12 || verif.eol != 4)
		return (0);
	else
		res = nb_link(map);
		return (res == 6 || res == 8 ? 1 : 0);
	*/
	return (0);
}



int		main(int ac, char **av)
{
	int fd;
	char **map;
	int n_read;
	int		x = 0;
	int		y;
	int		out;

	if(!(fd = (open(av[1], O_RDONLY))))
		ft_putendl("error");
	out = ft_reader(fd, map, &n_read);
	//ft_putnbr(out);
	//printf("%c\n", map[1][4]);
	ft_putchar('\n');
//	if (out > 0)
//		while (map[x])
//			ft_putstr(map[x++]);
//	else
//		ft_putendl("error out");
	close(fd);
	return (0);
}
