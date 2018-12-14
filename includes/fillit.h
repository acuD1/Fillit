/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:21:43 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/14 15:16:25 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"
# define COL 4
# define ROW 6
# define BUFF_LEN 1

# include <stdio.h>// a delete

typedef struct  s_verif
{
	int			hash;
	int			p;
	int			eol;
}				t_verif;

typedef struct	s_tetri
{
	char		coor[4][2];
	char		letter;
}				t_tetri;

void			fillit(void);
list			ft_parser(char *file);
int				ft_reader(int fd, char map[COL][ROW]);
void			ft_init(char map[COL][ROW], t_verif *verif);
int				next_tetri(int fd, char *buff);
int				ft_verif(char *c, t_verif *verif);
int				nb_link(char map[COL][ROW]);
int				fill_list(char tab[COL][ROW], list first);
void			printlist(list first);
void			printcoor(t_tetri *tetri);
void			printmap(char map[COL][ROW], int n);

#endif
