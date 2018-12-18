/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:08:21 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/18 16:41:11 by saneveu          ###   ########.fr       */
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
	res = ft_sqrt_supp(nb_lst);
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
void		solver(t_list **list)
{
	// -if safe
	// -place tetri
	// -else
	// -back nex step (use ft_strdel)
	// -if (map < need_len)
	//	-add 1 * 1 to map

}

int			safe(t_list **list, char **map)
{
	t_list 	*head;
	t_tetri *tetri;
	int		posx;
	int		posy;
	int		x;
	int		y;

	while(map[posx][posy] != '.' || map[posx][posy] != '\0')
		(map[posx][posy] == '\0' ? (posy = 0 && posx++) : posy++);
	
}
*/