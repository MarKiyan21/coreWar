/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_battle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 11:48:18 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 11:48:27 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

static int	cw_isgame(t_cw *cw)
{
	int	i;

	i = -1;
	while (++i < cw->chcount)
		if (cw->ch[i].alive)
			return (1);
	return (0);
}

static void	cw_decr_ctd(t_cw *cw)
{
	if (!cw->vm.cycle)
		return ;
	cw->vm.ctd -= CYCLE_DELTA;
	if (cw->vm.ctd < 1)
		cw->vm.ctd = 1;
	cw->vm.isdecr_maxcheck = true;
}

static void	cw_die_check(t_cw *cw)
{
	int i;
	int players;

	players = 0;
	i = -1;
	if (!cw->vm.cycle)
		return ;
	while (++i < cw->chcount)
	{
		if (!cw->ch[i].live)
			cw->ch[i].alive = false;
		else
		{
			cw->ch[i].live = 0;
			++players;
		}
	}
	cw->vm.checks++;
}

void		cw_battle(t_cw *cw)
{
	while (cw_isgame(cw))
	{
		if (cw->visual)
			cw_vis_refresh(cw);
		if (!(cw->vm.cycle % cw->vm.ctd))
			cw_die_check(cw);
		if (cw->vm.checks >= MAX_CHECKS && !cw->vm.isdecr_maxcheck)
		{
			cw->vm.checks = 0;
			cw_decr_ctd(cw);
		}
		cw_fight(cw);
		if (cw->vm.nbr_live >= NBR_LIVE)
		{
			cw->vm.nbr_live = 0;
			cw_decr_ctd(cw);
		}
		if (cw->dump == cw->vm.cycle && cw->isdump && !cw->visual)
			cw_output(cw);
		++cw->vm.cycle;
	}
	cw_the_end(cw);
}
