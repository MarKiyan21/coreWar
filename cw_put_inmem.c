/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_put_inmem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:54:06 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 14:54:08 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_put_inmem(t_cw *cw, int w, unsigned int i)
{
	cw->vm.mem[cw_real_ptr(w)] = i >> 24;
	cw->vm.mem[cw_real_ptr(w + 1)] = (i << 8) >> 24;
	cw->vm.mem[cw_real_ptr(w + 2)] = (i << 16) >> 24;
	cw->vm.mem[cw_real_ptr(w + 3)] = (i << 24) >> 24;
}
