/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:33:44 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/11/30 11:59:37 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;
	int		flag;
	char	*tmp;

	i = 0;
	flag = 0;
	tmp = dest;
	while (i < len)
	{
		if (src[i] == '\0' || flag == 1)
		{
			tmp[i] = '\0';
			flag = 1;
		}
		if (flag == 0)
			tmp[i] = src[i];
		i++;
	}
	return (dest);
}
