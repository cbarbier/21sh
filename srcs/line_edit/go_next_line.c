/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/01 04:43:33 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				go_next_line(t_21sh *e)
{
	int				lstln;
	int				end;

	ft_fprintf(e->ttyfd, "function go next line\n");
	if (e->curs.y < (lstln = e->curs.sy +
				((int)ft_strlen(e->prmpt) + e->ln) / e->co))
	{
		e->curs.y++;
		tputs(tgoto(tgetstr("DO", 0), 1, 0), 1, myput);
		if (e->curs.y == lstln)
		{
			end = ((int)ft_strlen(e->prmpt) + e->ln + 1) % e->co;
			if (end < e->curs.x)
				go_end(e);
		}
	}
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } START @ { %d : %d }\n",
			e->curs.x, e->curs.y, e->curs.sx, e->curs.sy);
	if (e->beg_sel != -2)
	{
		e->beg_sel = -2;
		refresh_line(e, e->line);
	}
	return (0);
}
