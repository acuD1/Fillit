/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:21:43 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/04 17:14:51 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"

void	fillit(void);

typedef struct  s_verif
{
    int     hash;
    int     p;
    int     eol;
}               t_verif;

typedef struct  s_tetri
{
    char        tetri[4][2];
    char        letter;
}               t_tetri;

#endif
