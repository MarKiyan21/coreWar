/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:21:58 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/17 17:14:47 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			word++;
		while (str[i] != c && str[i])
			i++;
	}
	return (word);
}

static char	*ft_word(const char *str, char c, int *i)
{
	char	*s;
	int		k;

	if ((s = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))) == NULL)
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i = *i + 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i = *i + 1;
	return (s);
}

char		**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		words;
	char	**s;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	words = ft_count_words(str, c);
	if ((s = (char**)malloc(sizeof(char*) * (words + 1))) == NULL)
		return (NULL);
	while (str[i] && str[i] == c)
		i++;
	while (j < words && str[i])
	{
		s[j] = ft_word(str, c, &i);
		j++;
	}
	s[j] = NULL;
	return (s);
}
