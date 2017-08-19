/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:58:30 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/07 13:52:18 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*tmp;
	int		i;
	int		k;
	int		len;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((tmp = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	while (s1[k] != '\0')
	{
		tmp[i++] = s1[k];
		k++;
	}
	k = 0;
	while (s2[k] != '\0')
	{
		tmp[i++] = s2[k];
		k++;
	}
	tmp[i] = '\0';
	return (tmp);
}
