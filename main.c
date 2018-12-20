/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:24:39 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/20 16:57:45 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
	t_list	*list;
	//char	**map;

	list = NULL;
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit [source_file]");
		return (0);
//		while (1);
	}
	if (!(list = ft_parser(av[1])))
	{
		ft_putendl("error");
		return (0);
//		while (1);
	}
	/*
	if (!(map = ft_solver(&list)))
	{
		ft_putendl("error");
		return (0);
//		while (1);
	}
	else
	{
		while (*map)
			ft_putendl(*map++);
	}
	free(map);*/
	ft_solver(&list);
	return (0);
//	while (1);
}
