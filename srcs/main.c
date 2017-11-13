/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:33:24 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/13 19:13:18 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include <errno.h>

static int	myput(int c)
{
	write(1, &c, 1);
	return (0);
}

static int reset_terminal(struct termios *term)
{
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag = (ICANON | ECHO);
	if (tcgetattr(0, term) == -1)
		return (-1);
	return (0);
}

static int	init_termcaps(struct termios *term, char *term_name)
{
	if (!(term_name = getenv("TERM")))
		return (-1);
	if (tgetent(0, term_name) == ERR)
		return (-1);
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	struct termios		term;
	char				*term_name;
	char				buff[7];
	int					ttyfd;
	char				*res;
	char				*area;

	ft_printf("%s\n", argv[argc - 1]);
	if (!(ttyfd = open(argv[argc - 1], O_WRONLY, O_NONBLOCK)))
		return (ft_fprintf(ttyfd, "Error: can't open tty\n"));
	ft_fprintf(ttyfd, "### WELCOME 21SH ###\n");
	term_name = 0;
	if (init_termcaps(&term, term_name))
	{
		reset_terminal(&term);
		return (ft_fprintf(2, "Error: can't get term infos\n"));
	}
	ft_printf("test_cursor_moving\n");
	while (1)
	{
		ft_bzero(buff, 7);
		read(0, buff, 6);
		ft_fprintf(ttyfd, "[%x][%x][%x][%x][%x][%x]\n", (int)buff[0], (int)buff[1], (int)buff[2], (int)buff[3], (int)buff[4], (int)buff[5]);
		if (*buff == 4)
		{
			ft_fprintf(ttyfd, "ctrl + D catched\n");
			reset_terminal(&term);
			return (0);
		}
		res = tgetstr("nd", &area);
		tputs(tgoto(res, 0, 1), 1, myput); 
	}
	ft_printf("all good\n");
	return (0);
}
