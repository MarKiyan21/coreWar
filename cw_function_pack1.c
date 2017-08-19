/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_function_pack1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:47:52 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 12:47:53 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_vm_live(t_cw *cw, int c)
{
	int		champ;

	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 10);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	champ = cw_get_number(cw, cw->ch[c].pc + 1, cw->ch[c].pc + 1 + 1);
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + 1 + 1);
	if (champ >= cw->chcount)
		return ;
	++cw->ch[champ].live;
	++cw->vm.nbr_live;
	cw->vm.last_live = champ;
	if (cw->visual)
		return ;
	ft_putstr("A process shows that player ");
	ft_putnbr(champ);
	ft_putstr(" (");
	ft_putstr(cw->ch[champ].name);
	ft_putstr(") is alive\n");
}

void	cw_vm_ld(t_cw *cw, int c)
{
	unsigned int	**args;

	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 5);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	args = cw_get_arg(cw, c, 4, 1);
	if (!(args[0][0] == T_DIR || args[0][0] == T_IND) ||
		args[0][1] != T_REG || args[0][2])
	{
		cw->ch[c].carry = false;
		cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
		free_args(&(*args));
		return ;
	}
	cw->ch[c].reg[args[1][1]] = args[1][0];
	cw->ch[c].carry = true;
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
	free_args(&(*args));
}

void	cw_vm_st(t_cw *cw, int c)
{
	unsigned int	**args;

	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 5);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	args = cw_get_arg(cw, c, 2, 1);
	if (args[0][0] != T_REG || !(args[0][1] == T_REG || args[0][1] == T_IND) ||
		args[0][2])
	{
		cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
		free_args(&(*args));
		return ;
	}
	cw_load_reg(cw, c, args, 0);
	cw_put_inmem(cw, cw->ch[c].pc + (args[1][1] % IDX_MOD), args[1][0]);
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
	free_args(&(*args));
}

void	cw_vm_add(t_cw *cw, int c)
{
	unsigned int	**args;

	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 10);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	args = cw_get_arg(cw, c, 0, 0);
	if (args[0][0] != T_REG || args[0][1] != T_REG || args[0][2] != T_REG)
	{
		cw->ch[c].carry = false;
		cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
		free_args(&(*args));
		return ;
	}
	cw_load_reg(cw, c, args, 0);
	cw_load_reg(cw, c, args, 1);
	cw->ch[c].reg[args[1][2]] = args[1][0] + args[1][1];
	cw->ch[c].carry = true;
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
	free_args(&(*args));
}

void	cw_vm_sub(t_cw *cw, int c)
{
	unsigned int	**args;

	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 10);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	args = cw_get_arg(cw, c, 0, 0);
	if (args[0][0] != T_REG || args[0][1] != T_REG || args[0][2] != T_REG)
	{
		cw->ch[c].carry = false;
		cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
		free_args(&(*args));
		return ;
	}
	cw_load_reg(cw, c, args, 0);
	cw_load_reg(cw, c, args, 1);
	cw->ch[c].reg[args[1][2]] = args[1][0] - args[1][1];
	cw->ch[c].carry = true;
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
	free_args(&(*args));
}
