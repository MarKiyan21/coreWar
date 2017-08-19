//
// Created by Igor Repeta on 8/1/17.
//

#include "cw.h"

int		main(int argc, char **argv)
{
	t_cw	cw;

	cw_struct_null(&cw);
	cw_read_args(&cw, argc, argv);
	cw_decryptor(&cw);
	cw_prefight(&cw, 0);
	if (cw.visual)
		cw_pre_visual(&cw);
	cw_battle(&cw);
	int i = 0;
	//printf("|%d|\nOH GOD, WE DID IT!\n", cw.chcount);
	sleep(3);
	endwin();
	// initscr();
	// noecho();
	// curs_set(FALSE);
	// int row, col;
	// getmaxyx(stdscr,row,col);
	// mvprintw(row - 5, col -5, "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!%s\n", "\nhi guys");
	// refresh();
	// sleep(10);
	// endwin();
	return (0);
}
