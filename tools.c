/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 02:02:08 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/20 16:57:49 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

void	ft_free_list(t_list *list)
{
	t_list	*next;

	while (list != NULL)
	{
		next = list;
		list = list->next;
		free(next);
	}
}

void	ft_letter_assignation(t_list *list)
{
	int		cnt;
	t_list	*tmp;

	tmp = list;
	cnt = 0;
	while (tmp)
	{
		((t_tetri *)tmp->content)->letter = (char)('A' + cnt);
		cnt++;
		tmp = tmp->next;
	}
}

int		ft_min_map(t_list **list)
{
	int		nb_lst;
	int		res;

	nb_lst = ft_lstlen(*list);
	if (nb_lst == 1)
		res = 2;
	res = ft_sqrt_supp(nb_lst * 4);
	return (res);
}

char	*ft_strsetnew(char c, int size)
{
	char	*str;
	int		i;

	str = (char*)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (size--)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_create_map(int bsq)
{
	char	**map_y;
	char	*map_x;
	int		i;

	map_y = (char**)malloc((bsq + 1) * sizeof(char*));
	if (!map_y)
		return (NULL);
	i = bsq;
	map_y[i] = NULL;
	while (--i >= 0)
	{
		map_x = ft_strsetnew('.', bsq);
		map_y[i] = map_x;
	}
	return (map_y);
}
