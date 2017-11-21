/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_21sh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:33:24 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/21 17:49:29 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int	get_cursor_xy(t_21sh *e, t_cursor *curs)
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
	{
		curs->x = 10 * curs->x + (int)buff[i] - '0';
		ft_fprintf(e->ttyfd, "[%x]", (int)buff[i++]);
	}
	ft_fprintf(e->ttyfd, "\n");
	while (++i < ret && buff[i] != 'R')
	{
		curs->y = 10 * curs->y + (int)buff[i] - '0';
		ft_fprintf(e->ttyfd, "[%x]", (int)buff[i]);
	}
	ft_fprintf(e->ttyfd, "\n");
	ft_fprintf(e->ttyfd, "cursor x[%d] y[%d]\n", curs->x, curs->y); 
	return (0);
}

int		init_21sh(t_21sh *e, int argc, char **argv)
{
	ft_bzero(e, sizeof(t_21sh));
	e->run = 1;
	ft_strcpy(e->prpt, "$prompt>");
	if (!(e->ttyfd = open(argv[argc - 1], O_WRONLY | O_NONBLOCK)))
		return (ft_fprintf(2, "Error: can't open tty\n"));
	if (init_termcaps(e))
	{
		reset_terminal(e);
		return (ft_fprintf(2, "Error: can't get term infos\n"));
	}
	if (get_cursor_xy(e, &e->curs))
		return (ft_fprintf(2, "Error: can't get cursor\n"));
	ft_fprintf(e->ttyfd, "### WELCOME 21SH ###\n");
	ft_fprintf(e->ttyfd, "term nb cols: %d   nb lines: %d\n", tgetnum("co"), tgetnum("li"));
	return (0);
}
