/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:00:07 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/01 16:40:25 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	while (n != 0)
	{
		if (*((unsigned char*)str) == (unsigned char)c)
			return ((unsigned char*)str);
		str++;
		n--;
	}
	return (NULL);
}
