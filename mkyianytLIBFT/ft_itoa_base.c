/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:38:55 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/03/21 17:03:32 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long nb, int base)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0 && base == 10)
	{
		nb = -nb;
		i++;
	}
	else if (nb < 0)
		nb = -nb;
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

char		*ft_itoa_base(int value, int base)
{
	int		i;
	long	nb;
	char	*a;
	char	*s;

	a = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	i = ft_count((long)value, base);
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i--] = '\0';
	if (value < 0)
		nb = (long)value * -1;
	else
		nb = (long)value;
	while (nb > 0)
	{
		s[i--] = a[(nb % base)];
		nb /= base;
	}
	if (value < 0 && base == 10)
		s[0] = '-';
	if (value == 0)
		ft_null(s);
	return (s);
}
