/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:08:21 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/19 20:18:30 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_min_map(t_list **list)
{
	int 	nb_lst;
	int		res;

	nb_lst = ft_lstsize(*list);
	if (nb_lst == 1)
		res = 2;
	res = ft_sqrt_supp(nb_lst * 4);
	return (res);
}

char 		**create_map(int nb)
{
	char	**map;
	int		i;

	if (!(map = (char **)malloc(sizeof(char *) * nb)))
		return (NULL);
	i = 0;
	while (i < nb)
	{
		if(!(map[i] = (char *)malloc(sizeof(char) * nb + 1)))
			return (NULL);
		i++;
	}
	b_point(map, nb);
	return (map);
}

/*
int			ft_backtrack(t_list **list, char **map, int posx, int posy)
{
	if (safe(list, map, posx, posy))
	{
		place(list, map, posx, posy);
		return (1);
	}
	else if (map[posx][posy + 1])
		ft_backtrack(list, map, posx, posy + 1);
	else if (map[posx + 1])
		ft_backtrack(list, map, posx + 1, 0);
	return (0);
}

int			safe(t_list **list, char **map, int	posx, int posy)
{
	t_list 	*head;
	t_tetri *tetri;
	int		posx;
	int		posy;
	int		x;
	int		y;

	while(map[posx][posy] != '.')
		(map[posx][posy] == '\0' ? (posy = 0 && posx++) : posy++);
	if(map[posx + x][posy + y] == '.')
	{

	}

}
*/

int ft_check_si_tout_vas_bien(char **map,t_tetri *tetri, int pos, int i)
{
	int row;
	int col;

	col = 0;
	row = 0;
	row = pos / 4;
	col = pos % 4;
	if (pos%i + tetri->coor[0][1] >= i || pos%i + tetri->coor[0][1] < 0 || pos/i + tetri->coor[0][0] >= i || pos/i + tetri->coor[0][0] < 0 || map[pos/i + tetri->coor[0][0]][pos%i + tetri->coor[0][1]] != '.')
		return (0);
	else if (pos%i  + tetri->coor[1][1] >= i || pos%i  + tetri->coor[1][1] < 0 || pos/i + tetri->coor[1][0] >= i || pos/i + tetri->coor[1][0] < 0 || map[pos/i + tetri->coor[1][0]][pos%i  + tetri->coor[1][1]] != '.')
		return (0);
	else if (pos%i  + tetri->coor[2][1] >= i || pos%i  + tetri->coor[2][1] < 0 || pos/i + tetri->coor[2][0] >= i || pos/i + tetri->coor[2][0] < 0 || map[pos/i + tetri->coor[2][0]][pos%i  + tetri->coor[2][1]] != '.')
		return (0);
	else if (pos%i  + tetri->coor[3][1] >= i || pos%i  + tetri->coor[3][1] < 0 || pos/i + tetri->coor[3][0] >= i || pos/i + tetri->coor[3][0] < 0 || map[pos/i + tetri->coor[3][0]][pos%i  + tetri->coor[3][1]] != '.')
		return (0);
	return (1);
}

void ft_unplace_la_piece(char **map, t_tetri *tetri, int pos, int map_size)
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

void ft_place_la_piece(char **map, t_tetri *tetri, int pos, int map_size)
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

int 	fill_map(char **map, t_list *list, int pos, int i)
{
	if (list == NULL)
		return (1);
	while (pos < i * i)
	{
		if (ft_check_si_tout_vas_bien(map, ((t_tetri *)list->content), pos, i))
		{
			ft_place_la_piece(map, ((t_tetri *)list->content), pos, i);
			printf("Letter %c\n", ((t_tetri *)list->content)->letter);
			ft_display(map, i);
			if (fill_map(map, list->next, 0, i))
				return(1);
			else
				ft_unplace_la_piece(map, ((t_tetri *)list->content), pos, i);
		}
		pos++;
	}
	return (0);
}

void		solver(t_list **list)
{
	int		i;
	char	**map;

	i = ft_min_map(list);
	map = create_map(i);
	while ((fill_map(map, *list, 0, i)) == 0)
	{
		ft_display(map, i);
		// ft_free_map(map);
		free(map);
		i++;
		map = create_map(i);
		printf("NEW MAP ?\n");
	}
	printf("Final map\n");
	//ft_display(map, i);
}
