/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:16:17 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/07 13:42:54 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int a, size_t len)
{
	char	*s;
	char	*tmp;
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	tmp = (char*)str;
	if ((s = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	while (i < len)
	{
		s[i] = tmp[a];
		i++;
		a++;
	}
	s[i] = '\0';
	return (s);
}
