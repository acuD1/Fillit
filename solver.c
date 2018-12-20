/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:08:21 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/20 19:05:18 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

int			ft_check(char **map, t_tetri *t, int pos, int i)
{
	int y;
	int x;

	y = pos / i;
	x = pos % i;
	if (x + t->c[0][1] >= i || x + t->c[0][1] < 0 || y + t->c[0][0] >= i
		|| y + t->c[0][0] < 0 || map[y + t->c[0][0]][x + t->c[0][1]] != '.')
		return (0);
	else if (x + t->c[1][1] >= i || x + t->c[1][1] < 0 || y + t->c[1][0] >= i
		|| y + t->c[1][0] < 0 || map[y + t->c[1][0]][x + t->c[1][1]] != '.')
		return (0);
	else if (x + t->c[2][1] >= i || x + t->c[2][1] < 0 || y + t->c[2][0] >= i
		|| y + t->c[2][0] < 0 || map[y + t->c[2][0]][x + t->c[2][1]] != '.')
		return (0);
	else if (x + t->c[3][1] >= i || x + t->c[3][1] < 0 || y + t->c[3][0] >= i
		|| y + t->c[3][0] < 0 || map[y + t->c[3][0]][x + t->c[3][1]] != '.')
		return (0);
	return (1);
}

void		ft_unplace_tetri(char **map, t_tetri *t, int pos, int map_size)
{
	int x;
	int y;

	x = 0;
	y = 0;
	y = pos / map_size;
	x = pos % map_size;
	map[y + t->c[0][0]][x + t->c[0][1]] = '.';
	map[y + t->c[1][0]][x + t->c[1][1]] = '.';
	map[y + t->c[2][0]][x + t->c[2][1]] = '.';
	map[y + t->c[3][0]][x + t->c[3][1]] = '.';
}

void		ft_place_tetri(char **map, t_tetri *t, int pos, int map_size)
{
	int y;
	int x;

	x = 0;
	y = 0;
	y = pos / map_size;
	x = pos % map_size;
	map[y + t->c[0][0]][x + t->c[0][1]] = t->letter;
	map[y + t->c[1][0]][x + t->c[1][1]] = t->letter;
	map[y + t->c[2][0]][x + t->c[2][1]] = t->letter;
	map[y + t->c[3][0]][x + t->c[3][1]] = t->letter;
}

int			ft_fill_map(char **map, t_list *list, int i)
{
	int pos;

	pos = 0;
	if (list == NULL)
		return (1);
	while (pos < i * i)
	{
		if (ft_check(map, ((t_tetri *)list->content), pos, i))
		{
			ft_place_tetri(map, ((t_tetri *)list->content), pos, i);
			if (ft_fill_map(map, list->next, i))
				return (1);
			else
				ft_unplace_tetri(map, ((t_tetri *)list->content), pos, i);
		}
		pos++;
	}
	return (0);
}

void	free_map2(char ***map)
{
	int		i;

	i = -1;
	if (map != NULL && *map != NULL)
	{
		while ((*map)[++i] != NULL)
		{
			free((*map)[i]);
			(*map)[i] = NULL;
		}
		free(*map);
		*map = NULL;
	}
}

void		ft_solver(t_list **list)
{
	int		i;
	char	**map;

	i = ft_min_map(list);
	if ((map = ft_create_map(i)) == NULL)
		return ;
	while ((ft_fill_map(map, *list, i)) == 0)
	{
		i++;
		free(map);
		if ((map = ft_create_map(i)) == NULL)
			return ;
	}
	while (*map)
		ft_putendl(*map++);
	free_map2(&map);
}
