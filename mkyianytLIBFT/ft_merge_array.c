/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:43:44 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/06/21 15:43:45 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_merge_array(char **array, char *str)
{
	int		i;
	char	**new_array;
	char	**ptr;

	i = 0;
	ptr = array;
	while (array[i])
		i++;
	new_array = (char**)malloc(sizeof(char*) * (i + 2));
	i = -1;
	while (array[++i])
		new_array[i] = ft_strdup(array[i]);
	new_array[i] = ft_strdup(str);
	new_array[i + 1] = NULL;
	ft_free_array(ptr);
	return (new_array);
}
