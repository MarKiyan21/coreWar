/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:01:50 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/01 13:14:13 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *append, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = dest;
	while (tmp[i] != '\0')
		i++;
	while (append[j] != '\0' && len > 0)
	{
		tmp[i] = append[j];
		i++;
		j++;
		len--;
	}
	tmp[i] = '\0';
	return (dest);
}
