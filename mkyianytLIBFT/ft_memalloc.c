/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:17:27 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/07 13:25:42 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*a;
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if ((a = (void*)malloc(size)) == NULL)
		return (NULL);
	tmp = a;
	while (i < size)
	{
		tmp[i] = 0;
		i++;
	}
	return (a);
}
