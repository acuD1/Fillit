/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:31:38 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/17 20:46:39 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_back(t_list **begin_list, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	tmp = *begin_list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*begin_list = new;
}
