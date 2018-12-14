/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:31:38 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/14 13:41:20 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_back(t_list **begin_list, void *content)
{
	if (*begin_list)
	{
		if (((*begin_list)->next))
			ft_list_push_back(&((*begin_list)->next), content);
		else
			((*begin_list)->next) = ft_create_elem(content);
	}
	else
		(*begin_list) = ft_create_elem(content);
}
