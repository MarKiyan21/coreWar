//
// Created by Igor Repeta on 8/15/17.
//

#include "cw.h"

void	cw_pre_visual(t_cw *cw)
{
	int i;
	int col;

	cw->vis.width = VM_MEM_INLINE * 3 + 1 + 3 + SUB_MENU;
	col = MEM_SIZE / VM_MEM_INLINE;
	cw->vis.height = col + 4;
	cw->vis.win = initscr();
	noecho();		//nevvod
	curs_set(0);	//invisible cursor
	if (col < 25)
		col = 25;
	if(has_colors() == FALSE)
	{	endwin();
		//printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
	init_pair(10, COLOR_BLUE, COLOR_BLUE);
	attron(COLOR_PAIR(10));
	i = -1;
	while (++i < cw->vis.width)
	{
		mvprintw(0,i,"*");
		mvprintw(col + 3, i,"*");
		if (i < col + 4)
		{
			mvprintw(i,0,"*");
			mvprintw(i,VM_MEM_INLINE * 3 + 2,"*");
			mvprintw(i, cw->vis.width - 1,"*");
		}
	}
	attroff(COLOR_PAIR(10));
	init_pair(11, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(11));
	cw_vis_output(cw, 2, 2);
	attroff(COLOR_PAIR(11));
	cw->vis.cps = 42;
	cw->vis.cstart = 0;
	cw->vis.vids = 0;
	cw->vis.pause = 1;
	cw_draw_players(cw);
	cw_draw_options(cw);
	refresh();
}
