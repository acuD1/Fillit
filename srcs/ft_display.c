/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 02:04:27 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/20 02:30:40 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putletter(t_list *list)
{
	t_list	*tmp;
	t_tetri *tetri;
	char 	let;
	int x;
	int y;
	int l;

	x = 0;
	y = 0;
	let = 'A';
	tmp = list;
	while (tmp)
	{
		l = 0;
		tetri = tmp->content;
		while (l < 4)
		{
			tetri->coor[x][y++] = let;
			l++;
		}
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
void	ft_display(char **map, int i)
{
	int	j;

	j = -1;
	while (++j < i)
		ft_putendl(map[j]);
}

void	printcoor(t_tetri *tetri)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		printf("#|%d|", i);
		printf("y = %d ", tetri->coor[i][j]);
		printf("x = %d ", tetri->coor[i][j + 1]);
		printf("\n");
		i++;
	}
	printf("-----------------\n");
}

