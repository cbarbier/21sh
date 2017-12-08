/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/08 16:28:15 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				go_home(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function go home\n");
	e->curs.x = e->curs.sx;
	e->curs.y = e->curs.sy;
	tputs(tgoto(tgetstr("cm", 0), e->curs.x - 1, e->curs.y - 1), 1, myput);
	if (e->beg_sel != -2)
	{
		e->beg_sel = -2;
		return (refresh_line(e, e->line));
	}
	return (0);
}
