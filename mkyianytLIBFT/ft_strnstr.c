/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:13:46 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/01 17:17:52 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	const char	*a;
	const char	*b;
	size_t		i;

	b = to_find;
	if (*b == '\0')
		return ((char*)str);
	while (*str != '\0' && len != 0)
	{
		if (*str == *b)
		{
			i = 0;
			a = str;
			while ((*(a + i) == *(b + i) || *(b + i) == '\0') && i <= len)
			{
				if (*(b + i) == '\0')
					return ((char*)str);
				i++;
			}
			b = to_find;
		}
		str++;
		len--;
	}
	return (0);
}
