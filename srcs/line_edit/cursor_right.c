/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/12 00:43:35 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				curs_right(t_21sh *e)
{
	if (e->ln == e->n)
		ft_fprintf(e->ttyfd, "|||||||||||||||end of line reached\n");
	else
		e->n++;
	if (e->ln && e->beg_sel != -2)
		select_right(e);
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } START @ { %d : %d } n %d\n",
			e->curs.x, e->curs.y, e->curs.sx, e->curs.sy, e->n);
	return (0);
}
