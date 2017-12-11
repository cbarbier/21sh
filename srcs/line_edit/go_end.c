/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/11 21:25:47 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				go_end(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function go end\n");
	e->curs.x = (e->curs.sx + e->ln) % e->co;
	e->curs.y = e->curs.sy + (e->curs.sx + e->ln) / e->co;
	tputs(tgoto(tgetstr("cm", 0), e->curs.x - 1, e->curs.y - 1), 1, myput);
	if (e->beg_sel != -2)
	{
		e->beg_sel = -2;
		return (0);
	}
	return (0);
}
