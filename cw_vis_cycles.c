//
// Created by Igor Repeta on 8/17/17.
//

#include "cw.h"

void	cw_vis_cstart(t_cw *cw)
{

}

void	cw_vis_cend(t_cw *cw)
{
	cw_vis_output(cw, 2, 2);
	refresh();
}