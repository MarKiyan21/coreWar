/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:37:24 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/07 13:52:07 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char			*s;
	char			*tmp;
	unsigned int	i;

	i = 0;
	if (!str)
		return (NULL);
	if ((s = (char*)malloc(ft_strlen(str) + 1)) == NULL)
		return (NULL);
	tmp = (char*)str;
	while (str[i] != '\0')
	{
		s[i] = f(i, tmp[i]);
		i++;
	}
	s[i] = '\0';
	return (s);
}
