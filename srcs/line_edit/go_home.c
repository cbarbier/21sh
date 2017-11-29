/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/29 08:53:55 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				go_home(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function go home\n");
	e->curs.x = e->curs.sx + ft_strlen(e->prmpt);
	e->curs.y = e->curs.sy;
	tputs(tgoto(tgetstr("cm", 0), e->curs.x - 1, e->curs.y - 1), 1, myput);
	return (0);
}
