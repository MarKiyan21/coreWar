/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:34:48 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/05 16:28:48 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int	*dest;
	int i;

	i = 0;
	dest = (int*)malloc(sizeof(int) * (length));
	while (i < length)
	{
		dest[i] = f(tab[i]);
		i++;
	}
	return (dest);
}
