/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_arg_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 11:45:43 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 11:47:11 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_load_reg(t_cw *cw, int c, unsigned int **args, int argn)
{
	if (args[0][argn] == T_REG)
		args[1][argn] = cw->ch[c].reg[argn];
}
