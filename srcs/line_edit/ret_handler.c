/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2018/01/09 15:08:15 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

static int		to_history(t_21sh *e)
{
	t_list			*l;

	if (!(l = e->cmd))
	{
		ft_fprintf(e->ttyfd, "line empty => not in history\n");
		return (0);
	}
	if (e->hist[HIST_LEN - 1])
		ft_lstdel(e->hist + HIST_LEN - 1, del_line);
	e->line = 0;
	ft_memmove((e->hist + 1), e->hist, (HIST_LEN - 1) * sizeof(t_list *));
	e->hist[0] = l;
	return (0);
}

int				next_loop(t_21sh *e, char *str, int (*f)(t_21sh *))
{
	int			ret;

	e->beg_sel = -2;
	ret = 0;
	ret = refresh_line(e, e->line);
	reset_terminal(e);
	if (str)
		ft_fprintf(2, "\n%s\n", str);
	if (f)
		f(e);
	if (e->run)
		init_loop(e);
	return (ret);
}

static int		ret_handler_helper(t_21sh *e)
{
	int			i;

	if (!(i = quoting(e->cmd)))
	{
		to_history(e);
		e->cmd = 0;
		ft_fprintf(2, "\nquoting OK => parsing && executing the command\n");
		return (0);
	}
	set_prmpt(e, "dq> ");
	ft_printf("\n");
	return (1);
}

int				ret_handler(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function ret handler\n");
	ft_lstpushback(&e->cmd, e->line);
	go_end(e);
	next_loop(e, 0, ret_handler_helper);
	return (0);
}
