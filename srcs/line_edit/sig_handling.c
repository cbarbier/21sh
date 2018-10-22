/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:41:37 by cbarbier          #+#    #+#             */
/*   Updated: 2018/01/19 10:52:17 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

void				resize_handler(int sig)
{
	t_21sh		*e;

	(void)sig;
	e = get_e(0);
	init_termcaps(e);
	ft_fprintf(e->ttyfd, "in the resize handler\n");
	ft_fprintf(e->ttyfd, "last term cols: %d lines: %d\n", e->co, e->li);
	ft_bzero(&e->curs, sizeof(t_cursor));
	if (get_cursor_xy(e, &e->curs))
	{
		ft_fprintf(2, "Error: can't get cursor\n");
		return ;
	}
	e->co = tgetnum("co");
	e->li = tgetnum("li");
	ft_fprintf(e->ttyfd, "after term cols: %d lines: %d\n", e->co, e->li);
	if (e->li < e->ln / e->co)
	{
		ft_fprintf(1, "Error: 21sh: terminal too tiny \n");
		exit_21sh(e, 1);
		return ;
	}
	set_prmpt(e, "21sh$ ");
	next_loop(e, "/!\\ 21sh: warning: refresh because of resizing", 0);
}