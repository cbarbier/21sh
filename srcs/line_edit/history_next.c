/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:17:26 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/12 01:55:52 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

int				history_next(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function history next\n");
	if (e->beg_sel != -2)
		return (select_down(e));
	ft_lstdel(&e->line, del_line);
	if (e->histpos - 1 < 0)
	{
		e->histpos = -1;
		ft_fprintf(e->ttyfd, "beg of hist\n");
	}
	else
		e->line = ft_lstcpy(e->hist[--e->histpos], sizeof(t_input));
	e->ln = ft_lstlen(e->line);
	go_end(e);
	return (0);
}
