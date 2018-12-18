/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:08:21 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/18 13:51:59 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_min_map(t_list **list)
{
	int 	nb_lst;
	int		res;

	nb_lst = ft_lstsize(*list);
	printf("nb_lst = %d\n", nb_lst);
	if (nb_lst == 1)
		res = 2;
	res = ft_sqrt_supp(nb_lst);
	printf("res = %d\n", res);
	return (res);
}

char 		**create_map(int nb, t_list **list)
{
	char	**map;
	t_list	*tmp;
	int		i;
	int		x;
	int		y;

	tmp = *list;
	if (!(map = (char **)malloc(sizeof(char *) * nb)))
		return (NULL);
	i = 0;
	x = 0;
	y = 0;
	while (i < nb)
	{
		if(!(map[i] = (char *)malloc(sizeof(char) * nb)))
			return (NULL);
		*map = &((t_tetri *)tmp->content)->coor[x++][y++];
		printf("tetri %c\n", ((t_tetri *)tmp->content)->letter);
		printf("COOR %c\n", *map[i]);
		tmp = tmp->next;
		i++;
	}
	return(map);
}

void		ft_backtrack(t_list **list)
{
	int		i;
	int		nb;
	char	**map;

	i = 0;
	nb = ft_min_map(list);
	printf("nb_min_map = %d\n", nb);
	map = create_map(nb, list);
	while (map[i])
		printf("%c", *map[i++]);
}
