/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/30 21:42:13 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				curs_left(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function cursor left\n");
	if (e->curs.x == 1)
	{
		e->curs.y--;
		e->curs.x = e->co;
		tputs(tgetstr("up", 0), 1, myput); 
		tputs(tgoto(tgetstr("RI", 0), e->co, e->co), 1, myput); 
	}
	else if (!(e->curs.y == e->curs.sy
	&& e->curs.x == e->curs.sx + (int)ft_strlen(e->prmpt)))
	{
		e->curs.x--;
		tputs(tgetstr("le", 0), 1, myput); 
	}
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } START @ { %d : %d }\n", e->curs.x, e->curs.y, e->curs.sx, e->curs.sy);
	if (e->ln && e->beg_sel != -2)
	{
		e->beg_sel = -2;
		refresh_line(e, e->line);
	}
	return (0);
}
