/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:48:59 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/01 17:15:39 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	const char	*a;
	const char	*b;

	b = to_find;
	if (*b == '\0')
		return ((char*)str);
	while (*str != '\0')
	{
		if (*str == *b)
		{
			a = str;
			while (*a == *b || *b == '\0')
			{
				if (*b == '\0')
					return ((char*)str);
				a++;
				b++;
			}
			b = to_find;
		}
		str++;
	}
	return (0);
}
