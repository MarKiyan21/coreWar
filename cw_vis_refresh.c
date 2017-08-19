//
// Created by Igor Repeta on 8/17/17.
//

#include "cw.h"

void	cw_vis_refresh(t_cw *cw)
{
	double time;
	struct timespec tt;
	int 	key;

	nodelay(cw->vis.win, TRUE);
	key = getch();
	if (key == 27)
		cw_the_end(cw);
	if (key == 32)
		cw->vis.pause = 1;
	if (key == 61 || key == 43)
		cw_vis_cps_up(cw);
	if (key > 0)
		printf("|%d|\n", key);
	while (cw->vis.pause)
	{
		key = getch();
		if (key > 0)
			printf("|%d|\n", key);
		if (key == 27)
			cw_the_end(cw);
		if (key == 32)
			cw->vis.pause = 0;
	}
	if (!cw->vis.cycles)
	{
		cw->vis.cstart = clock();
		cw->vis.cycles = 1;
	}
	else if (cw->vis.cycles > cw->vis.cps)
	{
		if ((time = ((1 - ((double)(clock() - cw->vis.cstart) / (double) CLOCKS_PER_SEC)))) > 0)
		{
			time *= 1000000;
			//printf("|%d|\n", usleep(time));
		}
		cw->vis.cycles = 0;
	}
	else
		++cw->vis.cycles;
	cw_vis_output(cw, 2, 2);
	refresh();
}