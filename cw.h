/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 11:37:46 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 11:39:19 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_H
# define CW_H

# include "op.h"
# include "libft/libft.h"

# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

#include <stdbool.h>

#include <ncurses.h>
#include <math.h>
#include <time.h>

#include <stdio.h> /////////////////////////// REMOVE!!!! //////////////////////////

#define VM_MEM_INLINE	64

#define SUB_MENU	42

typedef struct		s_ch
{
	bool			ischampion;			//чемпіон чи тільки процес?
	char 			*file;				//назва файлу звідки запускаємося
	bool			isnum;				//чемпіку задали номер
	int				num;				//number
	char 			*name;				//name
	int				csize;				//cmd size
	char 			*cmt;				//comment
	char			*cmd;				//commands
	unsigned char	*ucmd;				//uns cmd
	unsigned int	reg[REG_NUMBER];	//regs
	unsigned int	pc;					//program counter
	bool			carry;				//flag
	bool			alive;				//чи досі живий
	int				live;				//скільки лів за одну перевірку
	int				load_mem;			//load address
	bool			cpause;				//чи знаходимося в паузі
	int				cycles;				//кількість циклів до вихода з паузи
	short int		color;
}					t_ch;				//champion struct

typedef struct		s_vm
{
	unsigned char	*mem;				//battlefield
	unsigned int	cycle;				//який зараз цикл?
	unsigned int	ctd;				//CYCLE_TO_DIE
	int				checks;
	bool			isdecr_maxcheck;	//is ctd was decresed since MAX_CHECKS
	int				nbr_live;
	int				last_live;
}					t_vm;

typedef struct		s_vis
{
	WINDOW			*win;
	int				width;
	int				height;
	int				cps;				//cycles per second
	clock_t			cstart;				//cycle start time
	int 			cycles;				//cycles from "start" time
	int				vids;
	bool			pause;
}					t_vis;

/*
 * структура, яка виплила із-за норм
 */

typedef struct		s_n
{
	int				b;
	char			*n;
	unsigned int	**as;
}					t_n;

typedef struct	s_cw
{
	t_ch			*ch;		//champions
	int				chcount;	//champions number
	bool			visual;		//visual flag
	bool			isdump;		//чи задавали дамп
	int				dump;		//цикл дампа
	t_vm			vm;			//virtual machine-shit
	t_vis			vis;		//visual shits
	t_n				n;
}					t_cw;		//main struct

/*
 * тута будуть складові функції програми які онлі під корвар
 */

void				cw_struct_null(t_cw *cw);
void				cw_read_args(t_cw *cw, int argc, char **argv);
void				cw_read_args_flags(t_cw *cw, int argc, char **argv, int *i);
void				cw_decryptor(t_cw *cw);
void				cw_decrypt_magic(int fd);
char				*cw_decrypt_name(int fd);
int					cw_decrypt_cmd_size(int fd);
char				*cw_decrypt_comment(int fd);
void				cw_decrypt_commands(t_cw *cw, int z, int j, int fd);
void				cw_prefight(t_cw *cw, int tmp);
void				cw_pre_visual(t_cw *cw);
void				cw_battle(t_cw *cw);
void				cw_fight(t_cw *cw);
void				cw_the_end(t_cw *cw);

/*
 * FUCKING FUCK FUNCTIONS!
 */

void				cw_vm_live(t_cw *cw, int c);
void				cw_vm_ld(t_cw *cw, int c);
void				cw_vm_st(t_cw *cw, int c);
void				cw_vm_add(t_cw *cw, int c);
void				cw_vm_sub(t_cw *cw, int c);
void				cw_vm_and(t_cw *cw, int c);
void				cw_vm_or(t_cw *cw, int c);
void				cw_vm_xor(t_cw *cw, int c);
void				cw_vm_zjmp(t_cw *cw, int c);
void				cw_vm_ldi(t_cw *cw, int c);
void				cw_vm_sti(t_cw *cw, int c);
void				cw_vm_fork(t_cw *cw, int c);
void				cw_vm_lld(t_cw *cw, int c);
void				cw_vm_lldi(t_cw *cw, int c, int i);
void				cw_vm_lfork(t_cw *cw, int c);
void				cw_vm_aff(t_cw *cw, int c);
void				cw_vm_next(t_cw *cw, int c);
/*
 * тута функції які тіпа так само онлі під корвар але важать менше
 */

void				cw_output(t_cw *cw);
void				cw_usage(char *error);
void				cw_new_ch(t_cw *cw);
unsigned int		cw_get_number(t_cw *cw, int s, int e);
int					cw_real_ptr(int s);
char 				*cw_int_decrypt(unsigned char c);
unsigned int		**cw_get_arg(t_cw *cw, int c, int label, int ind);
void				cw_put_inmem(t_cw *cw, int w, unsigned int i);
void				cw_set_pause(t_cw *cw, int c, int fcycle);
void				cw_load_reg(t_cw *cw, int c, unsigned int **args, int argn);
void				cw_create_regs(t_cw *cw, int i);
void				cw_cpy_ch(t_cw *cw, int c, unsigned where, int ind);
void				cw_vis_output(t_cw *cw, int x, int y);
void				cw_vis_refresh(t_cw *cw);
void				cw_draw_options(t_cw *cw);
void				cw_draw_players(t_cw *cw);
void				cw_vis_cps_up(t_cw *cw);
void				cw_vis_cps_down(t_cw *cw);

/*
 * функції, які виплили із-за норм
 */

void				free_args(unsigned int **args);
int					is_pause(t_cw *cw, int c);

#endif
