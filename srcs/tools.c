/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 02:02:08 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/16 17:15:04 by arsciand         ###   ########.fr       */
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

void	ft_letter(t_list *first)
{
	t_list		*list;
	t_tetri		*tetri;
	char		c;

	c = 'A';
	list = first;
	while (list)
	{
		tetri = list->content;
		tetri->letter = c;
		c += 1;
		list = list->next;
	}
}

void	ft_letter_assignation(t_list *first, t_tetri *tetri)
{
	int		cnt;
	t_list	*tmp;

	tmp = first;
	cnt = 0;
	while (tmp)
	{
		tetri->letter = (char)('A' + cnt);
		cnt++;
		tmp = tmp->next;
	}
}
