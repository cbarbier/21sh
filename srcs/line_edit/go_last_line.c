/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_last_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/11 21:26:50 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				go_last_line(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function go last line\n");
	if (e->curs.y == e->curs.sy + 1 && e->curs.x <= e->curs.sx)
	{
		ft_fprintf(e->ttyfd, "just under the prompt => can't move");
		return (0);
	}
	if (e->curs.y > e->curs.sy)
	{
		e->curs.y--;
		tputs(tgetstr("up", 0), 1, myput);
	}
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } START @ { %d : %d }\n",
			e->curs.x, e->curs.y, e->curs.sx, e->curs.sy);
	if (e->beg_sel != -2)
		e->beg_sel = -2;
	return (0);
}
