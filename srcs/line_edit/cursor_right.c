/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/27 21:40:16 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				curs_right(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function cursor right\n");
	if (e->curs.x < e->co)
	{
		e->curs.x++;
		tputs(tgetstr("nd", 0), 1, myput); 
	}
	else
	{
		e->curs.x = 1;
		e->curs.y++;
		tputs(tgetstr("do", 0), 1, myput); 
		tputs(tgetstr("cr", 0), 1, myput); 
	}
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d }\n", e->curs.x, e->curs.y);
	return (0);
}
