/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:33:24 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/21 10:54:38 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int			 reset_terminal(struct termios *term)
{
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag = (ICANON | ECHO);
	if (tcgetattr(0, term) == -1)
		return (-1);
	tputs(tgetstr("ei", 0), 1, myput); 
	return (0);
}

int			init_termcaps(struct termios *term, char *term_name)
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
