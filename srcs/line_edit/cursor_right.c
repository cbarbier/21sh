/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/07 15:11:10 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				curs_right(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function curs right\n");
	if (e->c.p == e->in.ln) 
	{
		ft_fprintf(e->ttyfd, "end of line\n");
		return (0);
	}
	e->c.p++;
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } POS [%d] START @ { %d : %d }\n", e->c.x, e->c.y, e->c.p, e->c.sx, e->c.sy);
	return (0);
}
