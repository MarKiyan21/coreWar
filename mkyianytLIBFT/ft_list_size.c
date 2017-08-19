/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:51:25 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/05 18:20:01 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = begin_list;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
