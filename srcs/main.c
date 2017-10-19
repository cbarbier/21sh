/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:33:24 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/19 09:56:43 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

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
	char				buff[4];

	(void)argc;
	(void)argv;
	term_name = 0;
	if (init_termcaps(&term, term_name))
	{
		reset_terminal(&term);
		return (ft_fprintf(2, "Error: can't get term infos\n"));
	}
	while (1)
	{
		ft_bzero(buff, 4);
		read(0, buff, 3);
		ft_printf("buff: %d %d %d\n", (int)buff[0], (int)buff[1], (int)buff[2]);
		if (*buff == 4)
		{
			reset_terminal(&term);
			return (0);
		}
	}
	ft_printf("all good\n");
	return (0);
}

