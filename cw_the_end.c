/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_the_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:47:34 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 16:47:46 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_the_end(t_cw *cw)
{
	printf("\nWINNER! |%s| WON!\n", cw->ch[cw->vm.last_live].name);
	exit(0);
}