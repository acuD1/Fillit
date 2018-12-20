/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 02:02:08 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/20 03:17:36 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_init(char map[COL][ROW], t_verif *verif)
{
	int c;

	c = COL;
	verif->hash = 0;
	verif->p = 0;
	verif->eol = 0;
	while (c--)
		ft_bzero(map[c], ROW);
}

void	free_list(t_list **list)
{
	t_list	*next;

	while (list != NULL && *list != NULL)
	{
		next = (*list)->next;
		free(*list);
		*list = next;
	}
	list = NULL;
}

void 	ft_letter_assignation(t_list *first)
{
	int		cnt;
	t_list	*tmp;

	tmp = first;
	cnt = 0;
	while (tmp)
	{
	 	((t_tetri *)tmp->content)->letter = (char)('A' + cnt);
		cnt++;
		tmp = tmp->next;
	}
}

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

	if (!(map = (char **)malloc(sizeof(char *) * nb + 1)))
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
