/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/12 00:44:02 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				curs_left(t_21sh *e)
{
	int			i;

	ft_fprintf(e->ttyfd, "function cursor left\n");
	i = e->curs.x - e->curs.sx + (e->curs.y - e->curs.sy) * e->co;
	if (!e->n)
	{
		ft_fprintf(e->ttyfd, "cant move cursor left\n");
	}
	else
		e->n--;
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } START @ { %d : %d } n %d\n",
			e->curs.x, e->curs.y, e->curs.sx, e->curs.sy, e->n);
	if (e->beg_sel != -2)
		select_left(e);
	return (0);
}
