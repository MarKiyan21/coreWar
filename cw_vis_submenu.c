//
// Created by Igor Repeta on 8/18/17.
//

#include "cw.h"

void	cw_draw_players(t_cw *cw)
{
	int 		i;
	int 		j;
	short int	colors;

	if (!cw->vis.vids)
		cw->vis.vids = (cw->vis.height - (cw->chcount * 3 + 10)) / 2;
	j = 0;
	i = -1;
	if (!cw->ch[0].color)
	{
		colors = 1;
		while (++i < cw->chcount)
		{
			cw->ch[i].color = colors;
			init_pair(colors, colors, COLOR_BLACK);
			colors++;
			if (colors > 6)
				colors = 1;
		}
		i = -1;
	}
	while (++i < cw->chcount)
	{
		attron(COLOR_PAIR(cw->ch[i].color));
		mvprintw(cw->vis.vids + j, cw->vis.width - SUB_MENU, " P%d: %.33s", cw->ch[i].num, cw->ch[i].name);
		j++;
		mvprintw(cw->vis.vids + j, cw->vis.width - SUB_MENU, " Lives: %d", cw->ch[i].live);
		j += 2;
		attroff(COLOR_PAIR(cw->ch[i].color));
	}
}

void	cw_draw_options(t_cw *cw)
{
	char	*tab;

	tab = "----------------------------------------\0";
	init_pair(100, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(100));
	mvprintw(cw->vis.vids + cw->chcount * 3, cw->vis.width - SUB_MENU, "%s", tab);
	mvprintw(cw->vis.vids + cw->chcount * 3 + 2, cw->vis.width - SUB_MENU, " CYCLE_TO_DIE: %d", cw->vm.ctd);
	mvprintw(cw->vis.vids + cw->chcount * 3 + 4, cw->vis.width - SUB_MENU, " CYCLE_DELTA: %d", CYCLE_DELTA);
	mvprintw(cw->vis.vids + cw->chcount * 3 + 6, cw->vis.width - SUB_MENU, " NBR_LIVE: %d", NBR_LIVE);
	mvprintw(cw->vis.vids + cw->chcount * 3 + 8, cw->vis.width - SUB_MENU, " LIVES_FROM_LAST_CTD: %d", cw->vm.nbr_live);
	attroff(COLOR_PAIR(100));
}