/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:21:43 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/11 16:17:03 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"
# define COL 4
# define ROW 6
# define BUFF_LEN 1

typedef struct  s_verif
{
    int     hash;
    int     p;
    int     eol;
}               t_verif;

typedef struct  s_tetri
{
    char        **matrix;
    char        tetri[4][2];
    char        letter;
}               t_tetri;

void	    fillit(void);
int         ft_parser(char *file, t_list **list);
int         ft_reader(int fd, char map[COL][ROW]);
void	    ft_init(char map[COL][ROW], t_verif *verif);
#endif
