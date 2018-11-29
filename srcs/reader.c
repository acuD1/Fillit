/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:32:35 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/29 20:04:24 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     ft_verif(char c, t_verif verif)
{
    return (c == '#' ? ((verif.hash += 1) && 1) : 
    c == '.' ? ((verif.p += 1) && 1) :
    c == '\n' ? ((verif.eol += 1) && 1) : 0);
}

int     ft_reader(int fd, char map[4][6], int *n_read)
{
    int     res;
    char    buff;
    t_verif verif;
    int     x;
    int     y;

    n_read = 1;
    verif.hash = 0;
    verif.p = 0;
    verif.eol = 0;
    while (x < 4) 
    {
        y = 0;
        while (y < 6)
        {
            if (*n_read = read(fd, buff, 1) > 0)
                ft_verif(buff, verif) == 1 ? map[x][y] = buff : -1;
            y++
        }       
    }
}