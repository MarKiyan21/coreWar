/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:29:04 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/05 14:40:10 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*list;

	tmp = *alst;
	while (tmp)
	{
		list = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = list;
	}
	*alst = NULL;
}
