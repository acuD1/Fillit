/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:21:43 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/18 18:47:18 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"
# define COL 4
# define ROW 6
# define BUFF_LEN 1

# include <stdio.h>

typedef struct	s_verif
{
	int			hash;
	int			p;
	int			eol;
}				t_verif;

typedef struct	s_tetri
{
	char		coor[4][2];
	char		letter;
	int			placed;
}				t_tetri;

t_list			*ft_parser(char *file);
int				ft_reader(int fd, char map[COL][ROW]);
void			ft_init(char map[COL][ROW], t_verif *verif);
int				next_tetri(int fd, char *buff);
int				ft_verif(char *c, t_verif *verif);
int				nb_link(char map[COL][ROW]);
int				fill_list(char tab[COL][ROW], t_list **first);
void			free_list(t_list **list);

void			printlist(t_list **first);
void			printcoor(t_tetri *tetri);
void			printmap(char map[COL][ROW], int n);
void			ft_letter_assignation(t_list *list);
void			ft_putletter(t_list *list);
void			lst_print(t_list **list);

int				ft_min_map(t_list **list);
char			**create_map(int nb);
int				ft_sqrt_supp(int nb);
void			b_point(char **map, int size);

#endif
