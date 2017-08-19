/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:00:48 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/03 18:19:55 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *str)
{
	char	*tmp;
	int		i;
	int		j;
	int		el;

	i = 0;
	j = 0;
	el = 0;
	if (!str)
		return (NULL);
	while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t')
		j++;
	i = ft_strlen(str) - 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i--;
	if ((i - j) < 0)
		j = i;
	if ((tmp = (char*)malloc(i - j + 2)) == NULL)
		return (NULL);
	while (j <= i)
		tmp[el++] = str[j++];
	tmp[el] = '\0';
	return (&tmp[0]);
}
