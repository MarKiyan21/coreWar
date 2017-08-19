/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:27:34 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/01 16:36:56 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*tmp;

	tmp = dest;
	if (tmp >= (unsigned char*)src)
		while (len != 0)
		{
			len--;
			*(tmp + len) = *((unsigned char*)src + len);
		}
	else
		while (len != 0)
		{
			*tmp = *((unsigned char*)src);
			tmp++;
			src++;
			len--;
		}
	return (dest);
}
