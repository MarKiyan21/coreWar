/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:31:34 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/01 13:13:38 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *append)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = dest;
	while (tmp[i] != '\0')
		i++;
	while (append[j] != '\0')
	{
		tmp[i] = append[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (dest);
}
