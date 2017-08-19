/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:04:17 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/07 13:28:16 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if ((tmp = (char*)malloc(size + 1)) == NULL)
		return (NULL);
	while (i <= size)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}
