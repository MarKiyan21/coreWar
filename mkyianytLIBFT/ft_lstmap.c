/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:24:32 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/05 18:40:33 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*list;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((tmp = (t_list*)malloc(sizeof(t_list) * ft_list_size(lst))) == NULL)
		return (NULL);
	list = f(ft_lstnew(lst->content, lst->content_size));
	tmp = list;
	while (lst->next)
	{
		lst = lst->next;
		list->next = f(ft_lstnew(lst->content, lst->content_size));
		list = list->next;
	}
	return (tmp);
}
