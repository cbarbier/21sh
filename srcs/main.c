/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:33:24 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/14 16:16:30 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include <errno.h>

static int	put_tc(int ttyfd,char *cap)
{
	char buff[7];

	ft_bzero(buff, 7);
	ft_strcat(buff, tgetstr(cap, 0));
		ft_fprintf(ttyfd, "capibility \"%s\" [%x][%x][%x][%x][%x][%x]\n", cap, (int)buff[0], (int)buff[1], (int)buff[2], (int)buff[3], (int)buff[4], (int)buff[5]);
		return (0);
}

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
	tputs(tgetstr("ei", 0), 1, myput); 
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
	tputs(tgetstr("im", 0), 1, myput); 
	return (0);
}

int		main(int argc, char **argv)
{
	struct termios		term;
	char				*term_buff;
	char				buff[7];
	int					ttyfd;

	ft_printf("%s\n", argv[argc - 1]);
	if (!(ttyfd = open(argv[argc - 1], O_WRONLY | O_NONBLOCK)))
		return (ft_fprintf(ttyfd, "Error: can't open tty\n"));
	ft_fprintf(ttyfd, "### WELCOME 21SH ###\n");
	term_buff = 0;
	if (init_termcaps(&term, term_buff))
	{
		reset_terminal(&term);
		return (ft_fprintf(2, "Error: can't get term infos\n"));
	}
	ft_fprintf(ttyfd, "term nb cols: %d   nb lines: %d\n", tgetnum("co"), tgetnum("li"));
	put_tc(ttyfd, "kh");
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
		if ((int)buff[2] == 0x43)
			tputs(tgetstr("nd", 0), 1, myput); 
		else if ((int)buff[2] == 0x44)
			tputs(tgetstr("le", 0), 1, myput); 
		else if ((int)buff[2] == 0x41)
			tputs(tgetstr("up", 0), 1, myput); 
		else if ((int)buff[2] == 0x42)
			tputs(tgoto(tgetstr("DO", &term_buff), 1, 0), 1, myput); 
	}
	ft_printf("all good\n");
	return (0);
}
