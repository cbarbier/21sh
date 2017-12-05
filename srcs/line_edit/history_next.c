/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:17:26 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/05 16:15:30 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				history_next(t_21sh *e)
{
	int				ret;

	ft_fprintf(e->ttyfd, "function history next\n");
	ft_lstdel(&e->line, del_line);
	if (e->histpos - 1 < 0)
	{
		e->histpos = -1;
		ft_fprintf(e->ttyfd, "beg of hist\n");
	}
	else
		e->line = ft_lstcpy(e->hist[--e->histpos], sizeof(t_input));
	e->beg_sel = -1;
	ret = refresh_line(e, e->line);
	go_end(e);
	return (ret);
}
