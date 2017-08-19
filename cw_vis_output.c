//
// Created by Igor Repeta on 8/16/17.
//

#include "cw.h"

void	cw_vis_output(t_cw *cw, int x, int y)
{
	char	*tab;
	char 	*str;
	int		i;
	int		xx;

	str = ft_strnew(2);
	tab = "0123456789abcdef\0";
	i = 0;
	while (i < MEM_SIZE)
	{
		xx = x;
		while ((i + 1) % VM_MEM_INLINE != 0)
		{
//			if (i % VM_MEM_INLINE)
//			{
//				mvprintw(y, x, " ");
//				x++;
//			}
//			str[0] = *(tab + (cw->vm.mem[i] >> 4));
//			mvprintw(y, x, str);
//			x++;
//			str[0] = *(tab + (cw->vm.mem[i] % 16));
			mvprintw(y, xx, "%.2x ", cw->vm.mem[i]);
			xx += 3;
			i++;
		}
		if (i >= MEM_SIZE)
			return ;
//		mvprintw(x, y, " ");
//		x++;
//		str[0] = *(tab + (cw->vm.mem[i] >> 4));
//		mvprintw(y, x, str);
//		str[0] = *(tab + (cw->vm.mem[i] % 16));
		mvprintw(y, xx, "%.2x ", cw->vm.mem[i]);
		y += 1;
		++i;
	}
}