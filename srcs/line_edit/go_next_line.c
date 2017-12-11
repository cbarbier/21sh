/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/11 21:15:01 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				go_next_line(t_21sh *e)
{
	int				lstln;
	int				end;

	ft_fprintf(e->ttyfd, "function go next line\n");
	if (e->curs.y < (lstln = e->curs.sy + (e->curs.sx + e->ln) / e->co))
	{
		e->curs.y++;
		tputs(tgoto(tgetstr("DO", 0), 1, 0), 1, myput);
		if (e->curs.y == lstln)
		{
			end = (e->curs.sx + e->ln ) % e->co;
			if (end < e->curs.x)
				go_end(e);
		}
	}
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } START @ { %d : %d }\n",
			e->curs.x, e->curs.y, e->curs.sx, e->curs.sy);
	return (0);
}
