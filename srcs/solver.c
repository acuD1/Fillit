/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:08:21 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/17 22:59:22 by saneveu          ###   ########.fr       */
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
		if(!(map[i] = (char *)malloc(sizeof(char) * nb)))
			return (NULL);
		i++;
	}
}