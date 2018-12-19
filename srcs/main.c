/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:24:39 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/19 11:54:06 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*int		main(int ac, char **av)
{
	t_list	*list;

	list = NULL;
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit [source_file]");
		return (0);
	}
	list = ft_parser(av[1]);
	//ft_backtrack(&list)
	return (0);
}*/

int		main(int ac, char **av)
{
	char **map;
	int		j = -1;
	t_list *list;
	int i;

	(void)ac;
	list = NULL;
	list = ft_parser(av[1]);
	i = ft_min_map(&list);
	map = create_map(i);
	while (++j < i)
		ft_putendl(map[j]);
	return (0);
}
