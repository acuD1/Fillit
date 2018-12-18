/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 02:02:08 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/18 16:37:30 by saneveu          ###   ########.fr       */
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

void	ft_putletter(t_list *list)
{
	t_list	*tmp;
	t_tetri *tetri;
	char 	let;

	tmp = list;
	while (tmp)
	{
		tetri = tmp->content;
		let = tetri->letter;
		ft_putstr("[");
		ft_putchar(let);
		ft_putstr("]->");
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void	lst_print(t_list **list)
{
	t_list	*tmp;
	t_tetri *tetriletter;
	char	let;
	int		i;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		tetriletter = tmp->content;
		let = tetriletter->letter;
		printf("Link |%c|\n", let);
		printcoor(((t_tetri *)tmp->content));
		tmp = tmp->next;
	}
}