/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:31:03 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/07 13:35:48 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	char	*s;
	char	*tmp;
	int		i;

	i = 0;
	if (!str || !f)
		return (NULL);
	if ((s = (char*)malloc(ft_strlen(str) + 1)) == NULL)
		return (NULL);
	tmp = (char*)str;
	while (str[i] != '\0')
	{
		s[i] = (*f)(tmp[i]);
		i++;
	}
	s[i] = '\0';
	return (&s[0]);
}
