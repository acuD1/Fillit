/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:50:38 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/05 14:37:54 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		do_read(char *file)
{
	char	*line_tetris;
	int		fd;
	char 	*tab[4];
	int 	i;

	if (!(fd = (open(file, O_RDONLY))))
	{
		ft_putendl("error");
		return (0);
	}
	i = 0;
	while ((get_next_line(fd, &line_tetris)) && i < 4)
	{
		tab[i] = ft_strdup(line_tetris);
		i++;
	}
	close(fd);
	return (0);
}
