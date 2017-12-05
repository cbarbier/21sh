/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/05 17:37:26 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int		curs_right_helper(t_21sh *e)
{
	if (e->curs.x < e->co)
	{
		e->curs.x++;
		tputs(tgetstr("nd", 0), 1, myput);
	}
	else
	{
		e->curs.x = 1;
		if (e->curs.y < e->li)
		{
			e->curs.y++;
			tputs(tgetstr("do", 0), 1, myput);
		}
		tputs(tgetstr("cr", 0), 1, myput);
	}
	return (0);
}

int				curs_right(t_21sh *e)
{
	int				i;

	i = e->curs.x - ft_strlen(e->prmpt) - 1 + (e->curs.y - e->curs.sy) * e->co;
	if ((int)ft_lstlen(e->line) == e->ln && i == e->ln)
		ft_fprintf(e->ttyfd, "|||||||||||||||end of line reached\n");
	else
		curs_right_helper(e);
	if (e->ln && e->beg_sel != -2)
	{
		e->beg_sel = -2;
		return (refresh_line(e, e->line));
	}
	return (0);
}
