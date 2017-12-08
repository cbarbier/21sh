/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_21sh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:33:24 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/08 16:22:41 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int			get_cursor_xy(t_21sh *e, t_cursor *curs)
{
	int		i;
	int		ret;
	char	buff[20];

	write(1, "\033[6n", 4);
	read(0, buff, 2);
	i = 0;
	ft_bzero(buff, 20);
	if ((ret = read(0, buff, 20)) <= 0)
		return (1);
	while (i < ret && buff[i] != ';')
		curs->y = 10 * curs->y + (int)buff[i++] - '0';
	ft_fprintf(e->ttyfd, "cursor x[%d] y[%d]\n", curs->x, curs->y);
	while (++i < ret && buff[i] != 'R')
		curs->x = 10 * curs->x + (int)buff[i] - '0';
	ft_fprintf(e->ttyfd, "cursor x[%d] y[%d]\n", curs->x, curs->y);
	curs->sx = curs->x;
	curs->sy = curs->y;
	return (0);
}

int			init_loop(t_21sh *e)
{
	if (init_termcaps(e))
	{
		reset_terminal(e);
		return (ft_fprintf(2, "Error: can't get term infos\n"));
	}
	ft_bzero(&e->curs, sizeof(t_cursor));
	ft_lstdel(&e->line, del_line);
	e->ln = 0;
	ft_printf("%s", e->prmpt);
	if (get_cursor_xy(e, &e->curs))
		return (ft_fprintf(2, "Error: can't get cursor\n"));
	e->co = tgetnum("co");
	e->li = tgetnum("li");
	ft_fprintf(e->ttyfd, "term nb cols: %d   nb lines: %d\n", e->co, e->li);
	e->beg_sel = -1;
	e->end_sel = -1;
	e->histpos = -1;
	return (0);
}

t_21sh		*get_e(t_21sh *ae)
{
	static t_21sh		*e = 0;

	if (ae)
		e = ae;
	return (e);
}

int			init_21sh(t_21sh *e, int argc, char **argv)
{
	ft_bzero(e, sizeof(t_21sh));
	get_e(e);
	if (!(e->ttyfd = open(argv[argc - 1], O_WRONLY | O_NONBLOCK)))
		return (ft_fprintf(2, "Error: can't open tty\n"));
	PRMPT("21sh$ \0", 7);
	e->run = 1;
	ft_fprintf(e->ttyfd, "### WELCOME 21SH ###\n");
	init_loop(e);
	return (0);
}
