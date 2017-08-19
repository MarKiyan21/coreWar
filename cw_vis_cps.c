//
// Created by Igor Repeta on 8/18/17.
//

#include "cw.h"

void	cw_vis_cps_up(t_cw *cw)
{
	if (cw->vis.cps == 1000)
		return ;
	++cw->vis.cps;
}

void	cw_vis_cps_down(t_cw *cw)
{
	if (cw->vis.cps == 1)
		return ;
	--cw->vis.cps;
}