/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/14 00:36:18 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int		to_history(t_21sh *e)
{
	t_list			*l;

	l = e->line;
	if (!l)
	{
		ft_fprintf(e->ttyfd, "line empty =< not in history\n");
		return (0);
	}
	if (e->hist[HIST_LEN - 1])
		ft_lstdel(&e->hist[HIST_LEN - 1], del_line);
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

	ft_lstpushback(&e->cmd, ft_lstcpy(e->line, sizeof(t_input)));
	e->line = 0;
	if (!(i = quoting(e->cmd)))
	{
		ft_fprintf(2, "\nquoting OK => parsing && executing the command\n");
		ft_memcpy(e->prmpt, "21sh$ \0", 7);
		return (0);
	}
	PRMPT("dq> \0", 5);
	ft_printf("\n");
	return (1);
}

int				ret_handler(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function ret handler\n");
	to_history(e);
	go_end(e);
	next_loop(e, 0, ret_handler_helper);
	return (0);
}
