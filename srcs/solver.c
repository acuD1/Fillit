/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:08:21 by arsciand          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/12/18 13:51:59 by arsciand         ###   ########.fr       */
=======
/*   Updated: 2018/12/18 18:47:16 by saneveu          ###   ########.fr       */
>>>>>>> sam
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_min_map(t_list **list)
{
	int 	nb_lst;
	int		res;

	nb_lst = ft_lstsize(*list);
<<<<<<< HEAD
	printf("nb_lst = %d\n", nb_lst);
	if (nb_lst == 1)
		res = 2;
	res = ft_sqrt_supp(nb_lst);
	printf("res = %d\n", res);
=======
	printf("nb_lst |%d|\n", nb_lst);
	if (nb_lst == 1)
		res = 2;
	res = ft_sqrt_supp(nb_lst * 4);
	printf("res |%d|\n", res);
>>>>>>> sam
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
		if(!(map[i] = (char *)malloc(sizeof(char) * nb + 1)))
			return (NULL);
		*map = &((t_tetri *)tmp->content)->coor[x++][y++];
		printf("tetri %c\n", ((t_tetri *)tmp->content)->letter);
		printf("COOR %c\n", *map[i]);
		tmp = tmp->next;
		i++;
	}
<<<<<<< HEAD
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
=======
	b_point(map, nb);
	return (map);
}
	
}

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
	else
		delete(prcedent sur la map);
		return (-1);
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

void		solver(t_list **list)
{
	// -if safe
	// -place tetri
	// -else
	// -back nex step (use ft_strdel)
	// -if (map < need_len)
	//	-add 1 * 1 to map
	char	**map;
	char	**tmp;
	t_list	*head;
	int		sqrt;
	int 	res;

	res = 1;
	sqrt = ft_min_map(list);
	map = create_map(sqrt);
	head = *list;
	while (head)
	{
		if (res = (ft_backtrack(list, map, posx, posy)) == 1)
			head = head->next;
		if (res == -1)

	}
>>>>>>> sam
