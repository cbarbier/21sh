/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:33:24 by cbarbier          #+#    #+#             */
/*   Updated: 2018/01/19 10:31:47 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

int			read_stdin(t_21sh *e)
{
	t_list		*new;
	t_input		in;

	ft_bzero(&in, sizeof(t_input));
	in.c = 0;
	while (read(0, &in.c, 1) > 0)
	{
		if (!(new = ft_lstnew(&in, sizeof(t_input))))
			return (-1);
		ft_lstadd(&e->cmd, new);
	}
	if (!in.c)
		return (-1);
	return (0);
}

int			reset_terminal(t_21sh *e)
{
	if (tcgetattr(0, &e->term) == -1)
		return (-1);
	e->term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, TCSANOW, &e->term) == -1)
		return (-1);
	return (0);
}

int			init_termcaps(t_21sh *e)
{
	char			*term_name;

	if (!(term_name = getenv("TERM")))
		return (-1);
	if (tgetent(0, term_name) == ERR)
		return (-1);
	if (tcgetattr(0, &e->term) == -1)
		return (-1);
	e->term.c_lflag &= ~(ICANON | ECHO);
	e->term.c_cc[VMIN] = 1;
	e->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &e->term) == -1)
		return (-1);
	return (0);
}
