/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:24:39 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/20 03:23:42 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_list	*list;
	char	**final_map;

	list = NULL;

	if (ac != 2)
	{
		ft_putendl("usage : ./fillit [source_file]");
		return (0);
	}
	if (!(list = ft_parser(av[1])))
	{
		ft_putendl("error");
		return (0);
	}
	if (!(final_map = solver(&list)))
	{
		ft_putendl("error");
		return(0);
	}
	else
		ft_display_final_map(final_map);
	return (0);
}
