/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:24:39 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/14 19:23:19 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int ac, char **av)
{
	list list;

	list = NULL;
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit [source_file]");
		return (0);
	}
	list = ft_parser(av[1]);
	free(list);
	return (0);
}
