/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/27 17:47:49 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				curs_left(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function cursor left\n");
	if (e->curs.x == 1)
	{
		e->curs.y--;
		e->curs.x = tgetnum("co");
		tputs(tgetstr("up", 0), 1, myput); 
		tputs(tgoto(tgetstr("RI", 0), e->curs.y, e->co), 1, myput); 
	}
	else if (!(e->curs.y == e->curs.sy
	&& e->curs.x == e->curs.sx + (int)ft_strlen(e->prmpt)))
	{
		e->curs.x--;
		tputs(tgetstr("le", 0), 1, myput); 
	}
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d }\n", e->curs.x, e->curs.y);
	return (0);
}
