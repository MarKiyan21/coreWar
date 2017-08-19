/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:02:18 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/22 16:17:05 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(unsigned long nb, int base)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

static void	ft_null(char *s)
{
	s[0] = '0';
	s[1] = '\0';
}

char		*ft_uitoa_base(unsigned long value, int base)
{
	int				i;
	unsigned long	nb;
	char			*a;
	char			*s;

	a = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	i = ft_count((unsigned long)value, base);
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i--] = '\0';
	nb = (unsigned long)value;
	while (nb > 0)
	{
		s[i--] = a[(nb % base)];
		nb /= base;
	}
	if (value == 0)
		ft_null(s);
	return (s);
}
