/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:10:02 by arsciand          #+#    #+#             */
/*   Updated: 2018/11/21 09:49:27 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*link;

	link = *alst;
	while (*alst)
	{
		link = (*alst)->next;
		ft_lstdelone(&(*alst), del);
		*alst = link;
	}
	*alst = NULL;
}
