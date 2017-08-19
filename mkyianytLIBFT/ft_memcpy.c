/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:54:01 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/01 13:12:59 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)dest;
	while (n > 0)
	{
		*tmp = *((unsigned char*)src);
		tmp++;
		src++;
		n--;
	}
	return (dest);
}
