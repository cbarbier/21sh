/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_21sh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:33:24 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/21 11:27:10 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int	get_cursor_xy(t_cursor *curs)
{
	int		i;
	char	buff[20];

	write(1, "\033[6n", 4);
	read(0, buff, 2);
	i = 0;
	ft_bzero(buff, 20);
	while (read(0, buff + i, 1) > 0 && buff[i] != ';')
		i++;
	curs->x = ft_atoi(buff);
	i = 0;
	ft_bzero(buff, 20);
	while (read(0, buff + i, 1) > 0 && buff[i] != 'R')
		i++;
	curs->y = ft_atoi(buff);
	return (0);
}

int		init_21sh(t_21sh *e, int argc, char **argv)
{
	struct termios		term;
	char				*term_buff;
	char				buff[7];

	ft_bzero (e, sizeof(t_21sh));
	if (!(e->ttyfd = open(argv[argc - 1], O_WRONLY | O_NONBLOCK)))
		return (ft_fprintf(2, "Error: can't open tty\n"));
	if (init_termcaps(&term, term_buff))
	{
		reset_terminal(&term);
		return (ft_fprintf(2, "Error: can't get term infos\n"));
	}
	if (!get_cursor_xy(&e->curs))
		return (ft_fprintf(2, "Error: can't get cursor\n"));
	ft_fprintf(e->ttyfd, "### WELCOME 21SH ###\n");
	ft_fprintf(ttyfd, "term nb cols: %d   nb lines: %d\n", tgetnum("co"), tgetnum("li"));
	return (0);
}
