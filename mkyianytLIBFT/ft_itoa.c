/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:17:04 by mkyianyt          #+#    #+#             */
/*   Updated: 2016/12/12 18:59:33 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_int_min(char *n)
{
	n[0] = '-';
	n[1] = '2';
	n[2] = '1';
	n[3] = '4';
	n[4] = '7';
	n[5] = '4';
	n[6] = '8';
	n[7] = '3';
	n[8] = '6';
	n[9] = '4';
	n[10] = '8';
	n[11] = '\0';
	return (n);
}

static void	ft_digits(int *nb, int *flag, int *tmp, int *i)
{
	*tmp = 1;
	*flag = 0;
	*i = 0;
	if (*nb < 0)
	{
		*flag = 1;
		*nb = *nb * (-1);
	}
	*i = *nb;
	while (*i > 9)
	{
		*i = *i / 10;
		*tmp = *tmp + 1;
	}
	*i = 0;
}

static void	ft_is_positive(char *n, int *flag, int *i)
{
	if (*flag == 1)
	{
		n[*i] = '-';
		*i = *i + 1;
	}
}

static void	ft_calc(char *n, int *nb, int *div, int *i)
{
	while (*div != 0)
	{
		n[*i] = *nb / *div % 10 + '0';
		*div = *div / 10;
		*i = *i + 1;
	}
	n[*i] = '\0';
}

char		*ft_itoa(int nb)
{
	char	*n;
	int		div;
	int		tmp;
	int		flag;
	int		i;

	div = 1;
	if (nb == -2147483648)
	{
		n = (char*)malloc(12);
		return (ft_int_min(n));
	}
	ft_digits(&nb, &flag, &tmp, &i);
	n = (char*)malloc(flag + tmp + 1);
	if (!n)
		return (0);
	ft_is_positive(n, &flag, &i);
	while (tmp > 1)
	{
		div = div * 10;
		tmp--;
	}
	ft_calc(n, &nb, &div, &i);
	return (n);
}
