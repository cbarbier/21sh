/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:41:37 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/07 14:06:09 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				resize_handler(int sig)
{
	t_21sh		*e;

	(void)sig;
	e = get_e(0);
	init_termcaps(e);
	ft_fprintf(e->ttyfd, "in the resize handler\n");
	ft_fprintf(e->ttyfd, "last term cols: %d lines: %d\n", e->t.co, e->t.li);
	ft_bzero(&e->c, sizeof(t_cursor));
	if (get_cursor_xy(e, &e->c))
	{
		ft_fprintf(2, "Error: can't get cursor\n");
		return ;
	}
	e->t.co = tgetnum("co");
	e->t.li = tgetnum("li");
	ft_fprintf(e->ttyfd, "ater term cols: %d lines: %d\n", e->t.co, e->t.li);
}
