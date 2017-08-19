/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:33:49 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/03 18:34:08 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		splitd(char const *str, int i, char z)
{
	int c;

	c = 0;
	while ((char)str[i] != z && str[i])
	{
		i++;
		c++;
	}
	return (c);
}