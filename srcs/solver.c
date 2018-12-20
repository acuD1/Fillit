/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:08:21 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/20 04:16:21 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int			ft_check_si_tout_vas_bien(char **map, t_tetri *tetri, int pos, int i)
{
	int row;
	int col;
	
	row = pos / i;
	col = pos % i;
	if (col + tetri->coor[0][1] > i || col + tetri->coor[0][1] < 0 || row + tetri->coor[0][0] > i 
	|| row + tetri->coor[0][0] < 0 || map[row + tetri->coor[0][0]][col + tetri->coor[0][1]] != '.')
		return (0);
	else if (col + tetri->coor[1][1] > i || col + tetri->coor[1][1] < 0 || row + tetri->coor[1][0] > i 
	|| row + tetri->coor[1][0] < 0 || map[row + tetri->coor[1][0]][col + tetri->coor[1][1]] != '.')
		return (0);
	else if (col + tetri->coor[2][1] > i || col + tetri->coor[2][1] < 0 || row + tetri->coor[2][0] > i 
	|| row + tetri->coor[2][0] < 0 || map[row + tetri->coor[2][0]][col + tetri->coor[2][1]] != '.')
		return (0);
	else if (col + tetri->coor[3][1] > i || col + tetri->coor[3][1] < 0 || row + tetri->coor[3][0] > i 
	|| row + tetri->coor[3][0] < 0 || map[row + tetri->coor[3][0]][col + tetri->coor[3][1]] != '.')
		return (0);
	return (1);
}

void		ft_unplace_la_piece(char **map, t_tetri *tetri, int pos, int map_size)
{
	int row;
	int col;

	col = 0;
	row = 0;
	row = pos / map_size;
	col = pos % map_size;
	map[row + tetri->coor[0][0]][col + tetri->coor[0][1]] = '.';
	map[row + tetri->coor[1][0]][col + tetri->coor[1][1]] = '.';
	map[row + tetri->coor[2][0]][col + tetri->coor[2][1]] = '.';
	map[row + tetri->coor[3][0]][col + tetri->coor[3][1]] = '.';
}

void		ft_place_la_piece(char **map, t_tetri *tetri, int pos, int map_size)
{
	int row;
	int col;

	col = 0;
	row = 0;
	row = pos / map_size;
	col = pos % map_size;
	map[row + tetri->coor[0][0]][col + tetri->coor[0][1]] = tetri->letter;
	map[row + tetri->coor[1][0]][col + tetri->coor[1][1]] = tetri->letter;
	map[row + tetri->coor[2][0]][col + tetri->coor[2][1]] = tetri->letter;
	map[row + tetri->coor[3][0]][col + tetri->coor[3][1]] = tetri->letter;
}

int			fill_map(char **map, t_list *list, int i)
{
	int pos;

	pos = 0;
	if (list == NULL)
		return (1);
	while (pos < i * i)
	{
		if (ft_check_si_tout_vas_bien(map, ((t_tetri *)list->content), pos, i))
		{
			ft_place_la_piece(map, ((t_tetri *)list->content), pos, i);
			ft_display(map, i);
			ft_putchar('\n');
			if (fill_map(map, list->next, i))
				return(1);
			else
				ft_unplace_la_piece(map, ((t_tetri *)list->content), pos, i);
		}
		pos++;
	}
	return (0);
}

char		**solver(t_list **list)
{
	int		i;
	char	**map;

	i = ft_min_map(list);
	map = create_map(i);
	while ((fill_map(map, *list, i)) == 0)
	{
		free(map);
		i++;
		map = create_map(i);
	}
	return (map);
}
